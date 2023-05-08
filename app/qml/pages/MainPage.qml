/*******************************************************************************
**
** Copyright (C) 2022 ru.auroraos
**
** This file is part of the My Aurora OS Application project.
**
** Redistribution and use in source and binary forms,
** with or without modification, are permitted provided
** that the following conditions are met:
**
** * Redistributions of source code must retain the above copyright notice,
**   this list of conditions and the following disclaimer.
** * Redistributions in binary form must reproduce the above copyright notice,
**   this list of conditions and the following disclaimer
**   in the documentation and/or other materials provided with the distribution.
** * Neither the name of the copyright holder nor the names of its contributors
**   may be used to endorse or promote products derived from this software
**   without specific prior written permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
** AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
** THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
** FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
** IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
** FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,
** OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
** PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
** LOSS OF USE, DATA, OR PROFITS;
** OR BUSINESS INTERRUPTION)
** HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
** WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE)
** ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
** EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**
*******************************************************************************/

import QtQuick 2.0
import QtQuick.Layouts 1.1
import Sailfish.Silica 1.0
import Template 1.0


ApplicationWindow {
    id: applicationWindow
    allowedOrientations: defaultAllowedOrientations

    Helper {
        id: helper
    }

    Loader {
        id: pageLoader
    }

    ApplicationListViewManager {
        id: applicationManager
    }

    Button {
        anchors.centerIn: parent
        id: button
        width: 230
        height: 100
        text: "Applications"
        onClicked: {
            if (!helper.checkInternetConnection_()) {
                noInternetMessage.visible = true
                exitButton.visible = true
                button.visible = false
                return
            }

            applicationManager.download()
            while (applicationManager.hasNext()) {
                if (parseInt(applicationManager.getId()) % 2 == 0) {
                    dataModel.append({id: applicationManager.getId(),
                                     text: applicationManager.getName() + " " + applicationManager.getVersion() + "\n" + applicationManager.getAuthor(),
                                     color: "orange"})
                } else {
                    dataModel.append({id: applicationManager.getId(),
                                     text: applicationManager.getName() + " " + applicationManager.getVersion() + "\n" + applicationManager.getAuthor(),
                                     color: "grey"})
                }


            }
            listView.visible = true
            button.visible = false
        }
    }

    ListModel {
        id: dataModel
    }

    ListView {
        id: listView
        visible: false
        anchors.fill: parent
        model: dataModel
        delegate: Rectangle {
            width: parent.width
            height: 150
            color: model.color
            Text {
                anchors.centerIn: parent
                text: model.text
            }
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    if (!helper.checkInternetConnection_()) {
                        noInternetMessage.visible = true
                        exitButton.visible = true
                        listView.visible = false
                        return
                    }
                    helper.download_(model.id);
                    applicationManager.invoke(model.id);
                }
            }
        }
    }

    Text {
        id: noInternetMessage
        text: "Нет интернета!"
        color: "red"
        x: 230
        y: 400
        visible: false
    }

    Button {
        anchors.centerIn: parent
        id: exitButton
        width: 150
        height: 100
        text: "Выйти"
        visible: false
        onClicked: {
            helper.quit_()
        }
    }
}
