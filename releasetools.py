# Copyright (C) 2012 The Android Open Source Project
# Copyright (C) 2013 The CyanogenMod Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

""" Custom OTA commands for d2 devices """

def FullOTA_InstallEnd(info):
  info.script.AppendExtra('ifelse(is_substring("I535", getprop("ro.bootloader")), run_program("/sbin/sh", "-c", "busybox cp -R /system/blobs/vzw/* /system/"));')
  info.script.AppendExtra('ifelse(is_substring("I535", getprop("ro.bootloader")), run_program("/sbin/sh", "-c", "busybox sed -i \'s/ro.com.google.clientidbase=android-google/ro.com.google.clientidbase=android-verizon/g\' /system/build.prop"));')
  info.script.AppendExtra('ifelse(is_substring("R530", getprop("ro.bootloader")), run_program("/sbin/sh", "-c", "busybox cp -R /system/blobs/r530/* /system/"));')
  info.script.AppendExtra('ifelse(is_substring("L710", getprop("ro.bootloader")), run_program("/sbin/sh", "-c", "busybox cp -R /system/blobs/spr/* /system/"));')
  info.script.AppendExtra('ifelse(is_substring("S960L", getprop("ro.bootloader")), run_program("/sbin/sh", "-c", "busybox cp -R /system/blobs/spr/* /system/"));')
  info.script.AppendExtra('ifelse(is_substring("S968C", getprop("ro.bootloader")), run_program("/sbin/sh", "-c", "busybox cp -R /system/blobs/vzw/* /system/"));')
  info.script.AppendExtra('ifelse(is_substring("I747", getprop("ro.bootloader")), run_program("/sbin/sh", "-c", "busybox cp -R /system/blobs/gsm/* /system/"));')
  info.script.AppendExtra('ifelse(is_substring("T999", getprop("ro.bootloader")), run_program("/sbin/sh", "-c", "busybox cp -R /system/blobs/gsm/* /system/"));')
  info.script.AppendExtra('ifelse(is_substring("SC06D", getprop("ro.bootloader")), run_program("/sbin/sh", "-c", "busybox cp -R /system/blobs/gsm/* /system/"));')
