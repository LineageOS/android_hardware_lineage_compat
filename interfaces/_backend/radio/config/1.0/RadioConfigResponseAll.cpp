#define LOG_TAG "android.hardware.radio.config@1.0::RadioConfigResponse"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hidl/manager/1.0/IServiceManager.h>
#include <android/hardware/radio/config/1.0/BpHwRadioConfigResponse.h>
#include <android/hardware/radio/config/1.0/BnHwRadioConfigResponse.h>
#include <android/hardware/radio/config/1.0/BsRadioConfigResponse.h>
#include <android/hidl/base/1.0/BpHwBase.h>
#include <hidl/ServiceManagement.h>

namespace android {
namespace hardware {
namespace radio {
namespace config {
namespace V1_0 {

const char* IRadioConfigResponse::descriptor("android.hardware.radio.config@1.0::IRadioConfigResponse");

__attribute__((constructor)) static void static_constructor() {
    ::android::hardware::details::getBnConstructorMap().set(IRadioConfigResponse::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hardware::IBinder> {
                return new BnHwRadioConfigResponse(static_cast<IRadioConfigResponse *>(iIntf));
            });
    ::android::hardware::details::getBsConstructorMap().set(IRadioConfigResponse::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hidl::base::V1_0::IBase> {
                return new BsRadioConfigResponse(static_cast<IRadioConfigResponse *>(iIntf));
            });
}

__attribute__((destructor))static void static_destructor() {
    ::android::hardware::details::getBnConstructorMap().erase(IRadioConfigResponse::descriptor);
    ::android::hardware::details::getBsConstructorMap().erase(IRadioConfigResponse::descriptor);
}

// Methods from ::android::hardware::radio::config::V1_0::IRadioConfigResponse follow.
// no default implementation for: ::android::hardware::Return<void> IRadioConfigResponse::getSimSlotsStatusResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_vec<::android::hardware::radio::config::V1_0::SimSlotStatus>& slotStatus)
// no default implementation for: ::android::hardware::Return<void> IRadioConfigResponse::setSimSlotsMappingResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info)

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> IRadioConfigResponse::interfaceChain(interfaceChain_cb _hidl_cb){
    _hidl_cb({
        ::android::hardware::radio::config::V1_0::IRadioConfigResponse::descriptor,
        ::android::hidl::base::V1_0::IBase::descriptor,
    });
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IRadioConfigResponse::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    (void)fd;
    (void)options;
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IRadioConfigResponse::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    _hidl_cb(::android::hardware::radio::config::V1_0::IRadioConfigResponse::descriptor);
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IRadioConfigResponse::getHashChain(getHashChain_cb _hidl_cb){
    _hidl_cb({
        (uint8_t[32]){162,233,183,170,9,247,148,38,247,101,131,129,116,224,75,111,154,62,108,139,118,185,35,252,23,5,99,34,7,186,212,75} /* a2e9b7aa09f79426f765838174e04b6f9a3e6c8b76b923fc1705632207bad44b */,
        (uint8_t[32]){236,127,215,158,208,45,250,133,188,73,148,38,173,174,62,190,35,239,5,36,243,205,105,87,19,147,36,184,59,24,202,76} /* ec7fd79ed02dfa85bc499426adae3ebe23ef0524f3cd6957139324b83b18ca4c */});
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IRadioConfigResponse::setHALInstrumentation(){
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IRadioConfigResponse::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    (void)cookie;
    return (recipient != nullptr);
}

::android::hardware::Return<void> IRadioConfigResponse::ping(){
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IRadioConfigResponse::getDebugInfo(getDebugInfo_cb _hidl_cb){
    ::android::hidl::base::V1_0::DebugInfo info = {};
    info.pid = -1;
    info.ptr = 0;
    info.arch = 
    #if defined(__LP64__)
    ::android::hidl::base::V1_0::DebugInfo::Architecture::IS_64BIT
    #else
    ::android::hidl::base::V1_0::DebugInfo::Architecture::IS_32BIT
    #endif
    ;
    _hidl_cb(info);
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IRadioConfigResponse::notifySyspropsChanged(){
    ::android::report_sysprop_change();
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IRadioConfigResponse::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
    return (recipient != nullptr);
}


::android::hardware::Return<::android::sp<::android::hardware::radio::config::V1_0::IRadioConfigResponse>> IRadioConfigResponse::castFrom(const ::android::sp<::android::hardware::radio::config::V1_0::IRadioConfigResponse>& parent, bool /* emitError */) {
    return parent;
}

::android::hardware::Return<::android::sp<::android::hardware::radio::config::V1_0::IRadioConfigResponse>> IRadioConfigResponse::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IRadioConfigResponse, ::android::hidl::base::V1_0::IBase, BpHwRadioConfigResponse>(
            parent, "android.hardware.radio.config@1.0::IRadioConfigResponse", emitError);
}

BpHwRadioConfigResponse::BpHwRadioConfigResponse(const ::android::sp<::android::hardware::IBinder> &_hidl_impl)
        : BpInterface<IRadioConfigResponse>(_hidl_impl),
          ::android::hardware::details::HidlInstrumentor("android.hardware.radio.config@1.0", "IRadioConfigResponse") {
}

void BpHwRadioConfigResponse::onLastStrongRef(const void* id) {
    {
        std::unique_lock<std::mutex> lock(_hidl_mMutex);
        _hidl_mDeathRecipients.clear();
    }

    BpInterface<IRadioConfigResponse>::onLastStrongRef(id);
}
// Methods from ::android::hardware::radio::config::V1_0::IRadioConfigResponse follow.
::android::hardware::Return<void> BpHwRadioConfigResponse::_hidl_getSimSlotsStatusResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_vec<::android::hardware::radio::config::V1_0::SimSlotStatus>& slotStatus) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioConfigResponse::getSimSlotsStatusResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        _hidl_args.push_back((void *)&slotStatus);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio.config", "1.0", "IRadioConfigResponse", "getSimSlotsStatusResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioConfigResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_slotStatus_parent;

    _hidl_err = _hidl_data.writeBuffer(&slotStatus, sizeof(slotStatus), &_hidl_slotStatus_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_slotStatus_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            slotStatus,
            &_hidl_data,
            _hidl_slotStatus_parent,
            0 /* parentOffset */, &_hidl_slotStatus_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < slotStatus.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                slotStatus[_hidl_index_0],
                &_hidl_data,
                _hidl_slotStatus_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::config::V1_0::SimSlotStatus));

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(1 /* getSimSlotsStatusResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio.config", "1.0", "IRadioConfigResponse", "getSimSlotsStatusResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwRadioConfigResponse::_hidl_setSimSlotsMappingResponse(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::radio::V1_0::RadioResponseInfo& info) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IRadioConfigResponse::setSimSlotsMappingResponse::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.radio.config", "1.0", "IRadioConfigResponse", "setSimSlotsMappingResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwRadioConfigResponse::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.writeBuffer(&info, sizeof(info), &_hidl_info_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(2 /* setSimSlotsMappingResponse */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.radio.config", "1.0", "IRadioConfigResponse", "setSimSlotsMappingResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}


// Methods from ::android::hardware::radio::config::V1_0::IRadioConfigResponse follow.
::android::hardware::Return<void> BpHwRadioConfigResponse::getSimSlotsStatusResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info, const ::android::hardware::hidl_vec<::android::hardware::radio::config::V1_0::SimSlotStatus>& slotStatus){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::config::V1_0::BpHwRadioConfigResponse::_hidl_getSimSlotsStatusResponse(this, this, info, slotStatus);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioConfigResponse::setSimSlotsMappingResponse(const ::android::hardware::radio::V1_0::RadioResponseInfo& info){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::radio::config::V1_0::BpHwRadioConfigResponse::_hidl_setSimSlotsMappingResponse(this, this, info);

    return _hidl_out;
}


// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BpHwRadioConfigResponse::interfaceChain(interfaceChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioConfigResponse::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_debug(this, this, fd, options);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioConfigResponse::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceDescriptor(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioConfigResponse::getHashChain(getHashChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getHashChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioConfigResponse::setHALInstrumentation(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_setHALInstrumentation(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwRadioConfigResponse::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    ::android::hardware::ProcessState::self()->startThreadPool();
    ::android::hardware::hidl_binder_death_recipient *binder_recipient = new ::android::hardware::hidl_binder_death_recipient(recipient, cookie, this);
    std::unique_lock<std::mutex> lock(_hidl_mMutex);
    _hidl_mDeathRecipients.push_back(binder_recipient);
    return (remote()->linkToDeath(binder_recipient) == ::android::OK);
}

::android::hardware::Return<void> BpHwRadioConfigResponse::ping(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_ping(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioConfigResponse::getDebugInfo(getDebugInfo_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getDebugInfo(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwRadioConfigResponse::notifySyspropsChanged(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_notifySyspropsChanged(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwRadioConfigResponse::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
    std::unique_lock<std::mutex> lock(_hidl_mMutex);
    for (auto it = _hidl_mDeathRecipients.rbegin();it != _hidl_mDeathRecipients.rend();++it) {
        if ((*it)->getRecipient() == recipient) {
            ::android::status_t status = remote()->unlinkToDeath(*it);
            _hidl_mDeathRecipients.erase(it.base()-1);
            return status == ::android::OK;
        }
    }
    return false;
}


BnHwRadioConfigResponse::BnHwRadioConfigResponse(const ::android::sp<IRadioConfigResponse> &_hidl_impl)
        : ::android::hidl::base::V1_0::BnHwBase(_hidl_impl, "android.hardware.radio.config@1.0", "IRadioConfigResponse") { 
            _hidl_mImpl = _hidl_impl;
            auto prio = ::android::hardware::getMinSchedulerPolicy(_hidl_impl);
            mSchedPolicy = prio.sched_policy;
            mSchedPriority = prio.prio;
            setRequestingSid(::android::hardware::getRequestingSid(_hidl_impl));
}

BnHwRadioConfigResponse::~BnHwRadioConfigResponse() {
    ::android::hardware::details::gBnMap->eraseIfEqual(_hidl_mImpl.get(), this);
}

// Methods from ::android::hardware::radio::config::V1_0::IRadioConfigResponse follow.
::android::status_t BnHwRadioConfigResponse::_hidl_getSimSlotsStatusResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioConfigResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;
    const ::android::hardware::hidl_vec<::android::hardware::radio::config::V1_0::SimSlotStatus>* slotStatus;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_slotStatus_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*slotStatus), &_hidl_slotStatus_parent,  reinterpret_cast<const void **>(&slotStatus));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_slotStatus_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::radio::config::V1_0::SimSlotStatus> &>(*slotStatus),
            _hidl_data,
            _hidl_slotStatus_parent,
            0 /* parentOffset */, &_hidl_slotStatus_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < slotStatus->size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::radio::config::V1_0::SimSlotStatus &>((*slotStatus)[_hidl_index_0]),
                _hidl_data,
                _hidl_slotStatus_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::config::V1_0::SimSlotStatus));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioConfigResponse::getSimSlotsStatusResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        _hidl_args.push_back((void *)slotStatus);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio.config", "1.0", "IRadioConfigResponse", "getSimSlotsStatusResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioConfigResponse*>(_hidl_this->getImpl().get())->getSimSlotsStatusResponse(*info, *slotStatus);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio.config", "1.0", "IRadioConfigResponse", "getSimSlotsStatusResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwRadioConfigResponse::_hidl_setSimSlotsMappingResponse(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwRadioConfigResponse::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::radio::V1_0::RadioResponseInfo* info;

    size_t _hidl_info_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*info), &_hidl_info_parent,  const_cast<const void**>(reinterpret_cast<void **>(&info)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IRadioConfigResponse::setSimSlotsMappingResponse::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)info);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.radio.config", "1.0", "IRadioConfigResponse", "setSimSlotsMappingResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IRadioConfigResponse*>(_hidl_this->getImpl().get())->setSimSlotsMappingResponse(*info);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.radio.config", "1.0", "IRadioConfigResponse", "setSimSlotsMappingResponse", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}


// Methods from ::android::hardware::radio::config::V1_0::IRadioConfigResponse follow.

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BnHwRadioConfigResponse::ping() {
    return ::android::hardware::Void();
}
::android::hardware::Return<void> BnHwRadioConfigResponse::getDebugInfo(getDebugInfo_cb _hidl_cb) {
    ::android::hidl::base::V1_0::DebugInfo info = {};
    info.pid = ::android::hardware::details::getPidIfSharable();
    info.ptr = ::android::hardware::details::debuggable()? reinterpret_cast<uint64_t>(this) : 0;
    info.arch = 
    #if defined(__LP64__)
    ::android::hidl::base::V1_0::DebugInfo::Architecture::IS_64BIT
    #else
    ::android::hidl::base::V1_0::DebugInfo::Architecture::IS_32BIT
    #endif
    ;
    _hidl_cb(info);
    return ::android::hardware::Void();
}

::android::status_t BnHwRadioConfigResponse::onTransact(
        uint32_t _hidl_code,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        uint32_t _hidl_flags,
        TransactCallback _hidl_cb) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (_hidl_code) {
        case 1 /* getSimSlotsStatusResponse */:
        {
            _hidl_err = ::android::hardware::radio::config::V1_0::BnHwRadioConfigResponse::_hidl_getSimSlotsStatusResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 2 /* setSimSlotsMappingResponse */:
        {
            _hidl_err = ::android::hardware::radio::config::V1_0::BnHwRadioConfigResponse::_hidl_setSimSlotsMappingResponse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        default:
        {
            return ::android::hidl::base::V1_0::BnHwBase::onTransact(
                    _hidl_code, _hidl_data, _hidl_reply, _hidl_flags, _hidl_cb);
        }
    }

    if (_hidl_err == ::android::UNEXPECTED_NULL) {
        _hidl_err = ::android::hardware::writeToParcel(
                ::android::hardware::Status::fromExceptionCode(::android::hardware::Status::EX_NULL_POINTER),
                _hidl_reply);
    }return _hidl_err;
}

BsRadioConfigResponse::BsRadioConfigResponse(const ::android::sp<::android::hardware::radio::config::V1_0::IRadioConfigResponse> impl) : ::android::hardware::details::HidlInstrumentor("android.hardware.radio.config@1.0", "IRadioConfigResponse"), mImpl(impl) {
    mOnewayQueue.start(3000 /* similar limit to binderized */);
}

::android::hardware::Return<void> BsRadioConfigResponse::addOnewayTask(std::function<void(void)> fun) {
    if (!mOnewayQueue.push(fun)) {
        return ::android::hardware::Status::fromExceptionCode(
                ::android::hardware::Status::EX_TRANSACTION_FAILED,
                "Passthrough oneway function queue exceeds maximum size.");
    }
    return ::android::hardware::Status();
}

::android::sp<IRadioConfigResponse> IRadioConfigResponse::tryGetService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwRadioConfigResponse>(serviceName, false, getStub);
}

::android::sp<IRadioConfigResponse> IRadioConfigResponse::getService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwRadioConfigResponse>(serviceName, true, getStub);
}

::android::status_t IRadioConfigResponse::registerAsService(const std::string &serviceName) {
    return ::android::hardware::details::registerAsServiceInternal(this, serviceName);
}

bool IRadioConfigResponse::registerForNotifications(
        const std::string &serviceName,
        const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification> &notification) {
    const ::android::sp<::android::hidl::manager::V1_0::IServiceManager> sm
            = ::android::hardware::defaultServiceManager();
    if (sm == nullptr) {
        return false;
    }
    ::android::hardware::Return<bool> success =
            sm->registerForNotifications("android.hardware.radio.config@1.0::IRadioConfigResponse",
                    serviceName, notification);
    return success.isOk() && success;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V1_0
}  // namespace config
}  // namespace radio
}  // namespace hardware
}  // namespace android
