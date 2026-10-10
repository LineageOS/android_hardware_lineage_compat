# Bluetooth audio V3 native ABI

These data types are copied from
`hardware/interfaces/bluetooth/audio/aidl/aidl_api/android.hardware.bluetooth.audio/3`.
Only the package name and VINTF stability annotations are changed. They are private
compatibility types, not a new Binder HAL. Keep the V3 fields and union order frozen.

The legacy Amlogic audio HAL returns `AudioConfiguration` by value. Its caller
allocates storage for the V3 C++ layout, which must not receive a V6 object.
`AudioConfiguration.cpp` converts through stable AIDL parcel encoding into these
legacy types. The extraction fixup redirects only that blob's `GetAudioConfig`
reference to `GetAudioConfV3`; modern callers continue using the original symbol.

The four V3 union alternatives are supported. Newer alternatives and conversion
errors return a default PCM configuration (zero sample rate). No Binder interface
or modern session object is replaced.
