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
import Sailfish.Silica 1.0
import Template 1.0


Page {
    id: page
    allowedOrientations: Orientation.All

    Helper {
        id: helper
    }
//    Timer {
//        id: timer
//    }
//    function delay(delayTime,cb) {
//        timer.interval = delayTime;
//        timer.repeat = false;
//        timer.triggered.connect(cb);
//        timer.start();
//    }

    Rectangle {
        id: rectangle1
        x: parent.width / 8
        y: 6 * parent.height / 16
        width: 6 * parent.width / 8
        height: parent.height / 16
        color: "purple"
        Text {
            anchors.centerIn: parent
            text: "скачать котика"
            color: "white"
            font { bold: true; pixelSize: 48 }
        }

        MouseArea {
            id: mouseArea
            anchors.fill: parent
            onClicked: {
                helper.download_();
                console.log("File must be downloaded")
                rectangle2.visible = true
                parent.visible = false
            }
        }
    }

    Rectangle {
        visible: false;
        id: rectangle2
        x: parent.width / 8
        y: 10 * parent.height / 16
        width: 6 * parent.width / 8
        height: parent.height / 16
        color: "purple"
        Text {
            anchors.centerIn: parent
            text: "удалить котика"
            color: "white"
            font { bold: true; pixelSize: 48 }
        }

        MouseArea {
            id: mouseArea2
            anchors.fill: parent
            onClicked: {
                parent.visible = false
                rectangle1.visible = true
                helper.delete_()
            }
        }
    }
}
