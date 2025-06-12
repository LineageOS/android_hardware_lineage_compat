#include <media/AudioSystem.h>
#include <string>
#include <utils/Errors.h>
#include <vector>

namespace android {
extern "C" {
status_t _ZN7android11AudioSystem24setDeviceConnectionStateE24audio_policy_dev_state_tRKNS_5media5audio6common9AudioPortE14audio_format_tb(
    audio_policy_dev_state_t state,
    const android::media::audio::common::AudioPort& port,
    audio_format_t encodedFormat, bool deviceSwitch);

status_t _ZN7android11AudioSystem24setDeviceConnectionStateE24audio_policy_dev_state_tRKNS_5media5audio6common9AudioPortE14audio_format_t(
    audio_policy_dev_state_t state,
    const android::media::audio::common::AudioPort& port,
    audio_format_t encodedFormat, bool deviceSwitch
) {
    return _ZN7android11AudioSystem24setDeviceConnectionStateE24audio_policy_dev_state_tRKNS_5media5audio6common9AudioPortE14audio_format_tb(
        state, port, encodedFormat, deviceSwitch);
}
}
}  // namespace android
