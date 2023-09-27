#include <hidl/Static.h>

namespace android {
namespace hardware {
namespace details {

// Deprecated; kept for ABI compatibility. Use getBnConstructorMap.
DoNotDestruct<BnConstructorMap> gBnConstructorMap{};

// Deprecated; kept for ABI compatibility. Use getBsConstructorMap.
DoNotDestruct<BsConstructorMap> gBsConstructorMap{};

} // namespace details
} // namespace hardware
} // namespace android
