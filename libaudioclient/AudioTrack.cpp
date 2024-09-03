/*
**
** Copyright 2008, The Android Open Source Project
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/

#include <media/AudioTrack.h>

namespace android {

typedef void (*legacy_callback_t)(int event, void* user, void* info);
class LegacyCallbackWrapper : public AudioTrack::IAudioTrackCallback {
    const AudioTrack::legacy_callback_t mCallback;
    void* const mData;

  public:
    LegacyCallbackWrapper(AudioTrack::legacy_callback_t callback, void* user)
        : mCallback(callback), mData(user) {}
    size_t onMoreData(const AudioTrack::Buffer& buffer) override {
        AudioTrack::Buffer copy = buffer;
        mCallback(AudioTrack::EVENT_MORE_DATA, mData, static_cast<void*>(&copy));
        return copy.size();
    }
    void onUnderrun() override { mCallback(AudioTrack::EVENT_UNDERRUN, mData, nullptr); }
    void onLoopEnd(int32_t loopsRemaining) override {
        mCallback(AudioTrack::EVENT_LOOP_END, mData, &loopsRemaining);
    }
    void onMarker(uint32_t markerPosition) override {
        mCallback(AudioTrack::EVENT_MARKER, mData, &markerPosition);
    }
    void onNewPos(uint32_t newPos) override {
        mCallback(AudioTrack::EVENT_NEW_POS, mData, &newPos);
    }
    void onBufferEnd() override { mCallback(AudioTrack::EVENT_BUFFER_END, mData, nullptr); }
    void onNewIAudioTrack() override {
        mCallback(AudioTrack::EVENT_NEW_IAUDIOTRACK, mData, nullptr);
    }
    void onStreamEnd() override { mCallback(AudioTrack::EVENT_STREAM_END, mData, nullptr); }
    size_t onCanWriteMoreData(const AudioTrack::Buffer& buffer) override {
        AudioTrack::Buffer copy = buffer;
        mCallback(AudioTrack::EVENT_CAN_WRITE_MORE_DATA, mData, static_cast<void*>(&copy));
        return copy.size();
    }
};
#ifdef __LP64__
#define orig \
    _ZN7android10AudioTrackC1E19audio_stream_type_tj14audio_format_t20audio_channel_mask_tm20audio_output_flags_tRKNS_2wpINS0_19IAudioTrackCallbackEEEi15audio_session_tNS0_13transfer_typeEPK20audio_offload_info_tRKNS_7content22AttributionSourceStateEPK18audio_attributes_tbfi
#else
#define orig \
    _ZN7android10AudioTrackC1E19audio_stream_type_tj14audio_format_t20audio_channel_mask_tj20audio_output_flags_tRKNS_2wpINS0_19IAudioTrackCallbackEEEi15audio_session_tNS0_13transfer_typeEPK20audio_offload_info_tRKNS_7content22AttributionSourceStateEPK18audio_attributes_tbfi
#endif

extern "C" void* orig(void* thisptr, audio_stream_type_t streamType, uint32_t sampleRate,
                      audio_format_t format, audio_channel_mask_t channelMask, size_t frameCount,
                      audio_output_flags_t flags,
                      const wp<AudioTrack::IAudioTrackCallback>& callback,
                      int32_t notificationFrames, audio_session_t sessionId,
                      AudioTrack::transfer_type transferType,
                      const audio_offload_info_t* offloadInfo,
                      const AttributionSourceState& attributionSource,
                      const audio_attributes_t* pAttributes, bool doNotReconnect,
                      float maxRequiredSpeed, audio_port_handle_t selectedDeviceId);

static wp<AudioTrack::IAudioTrackCallback> createCallback(legacy_callback_t callback, void* user) {
    if (callback) {
        return sp<LegacyCallbackWrapper>::make(callback, user);
    } else if (user) {
        LOG_ALWAYS_FATAL("Callback data provided without callback pointer!");
    }
    return NULL;
}

#ifdef __LP64__
#define newfnc \
    _ZN7android10AudioTrackC1E19audio_stream_type_tj14audio_format_t20audio_channel_mask_tm20audio_output_flags_tPFviPvS5_ES5_i15audio_session_tNS0_13transfer_typeEPK20audio_offload_info_tRKNS_7content22AttributionSourceStateEPK18audio_attributes_tbfi
#else
#define newfnc \
    _ZN7android10AudioTrackC1E19audio_stream_type_tj14audio_format_t20audio_channel_mask_tj20audio_output_flags_tPFviPvS5_ES5_i15audio_session_tNS0_13transfer_typeEPK20audio_offload_info_tRKNS_7content22AttributionSourceStateEPK18audio_attributes_tbfi
#endif

extern "C" void* newfnc(void* thisptr, audio_stream_type_t streamType, uint32_t sampleRate,
                        audio_format_t format, audio_channel_mask_t channelMask, size_t frameCount,
                        audio_output_flags_t flags, legacy_callback_t callback, void* user,
                        int32_t notificationFrames, audio_session_t sessionId,
                        AudioTrack::transfer_type transferType,
                        const audio_offload_info_t* offloadInfo,
                        const AttributionSourceState& attributionSource,
                        const audio_attributes_t* pAttributes, bool doNotReconnect,
                        float maxRequiredSpeed, audio_port_handle_t selectedDeviceId) {
    return orig(thisptr, streamType, sampleRate, format, channelMask, frameCount, flags,
                createCallback(callback, user), notificationFrames, sessionId, transferType,
                offloadInfo, attributionSource, pAttributes, doNotReconnect, maxRequiredSpeed,
                selectedDeviceId);
}

}  // namespace android
