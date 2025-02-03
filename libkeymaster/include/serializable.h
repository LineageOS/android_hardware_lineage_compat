/*
 * Copyright 2014 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

namespace keymaster {

/**
 * Extracts a uint32_t size from *buf_ptr, placing it in \p *size, and then reads *size bytes from
 * *buf_ptr, placing them in newly-allocated storage in *dest.  If there aren't enough bytes in
 * *buf_ptr, returns false.  Advances \p *buf_ptr to the next byte to be read.
 *
 * See \p append_size_and_data_to_buf().
 */
bool copy_size_and_data_from_buf(const uint8_t** buf_ptr, const uint8_t* end, size_t* size,
                                 std::unique_ptr<uint8_t[], std::default_delete<uint8_t[]>>* dest);

} // namespace keymaster
