#include "HifiAudioDeviceInfo.h"

void HifiAudioDeviceInfo::setMode(QAudio::Mode mode) {
    _mode = mode;
    setDeviceName();
}

void HifiAudioDeviceInfo::setIsDefault(bool isDefault) {
    _isDefault = isDefault;
    setDeviceName();
}

 void HifiAudioDeviceInfo::setDeviceName() {
  if (_isDefault) {
         if (_mode == QAudio::Mode::AudioInput) {
             _deviceName = "Default microphone (recommended)";
         } else {
             _deviceName = "Default audio (recommended)";
         }
     } else {
         _deviceName = _audioDeviceInfo.deviceName();
     }
 }

 