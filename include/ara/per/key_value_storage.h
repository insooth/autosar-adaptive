
/**
 * @file key_value_storage.h
 *
 * AUTOSAR Adaptive Persistency: Key-Value Storage
 *
 * Document Title: Specification of Persistency
 * Document Owner: AUTOSAR
 * Document Responsibility: AUTOSAR
 * Document Identification No: 858
 * Document Status: Final
 * Part of AUTOSAR Standard: Adaptive Platform
 * Part of Standard Release: 19-03
 *
 * See for LICENSE file for license information
 * SPDX-License-Identifier: MIT
 *
 * @{
 */

// for exposition only [--
#include <memory>  // shared_ptr
#include <string>
#include <string_view>
#include <vector>

namespace ara::core
{
template<class T> using Result = T;
using InstanceSpecifier        = int;
template<class T> using Vector = std::vector<T>;
using String                   = std::string;
using StringView               = std::string_view;
}
// --]

/** @req SWS_PER_00002 */
namespace ara::per
{
// for exposition only [--
template<class T> using SharedHandle = std::shared_ptr<T>;
// --]

/** @req SWS_PER_00052 */
ara::core::Result<SharedHandle<KeyValueStorage>>
OpenKeyValueStorage(ara::core::InstanceSpecifier kvs) noexcept;

/** @req SWS_PER_00333 */
ara::core::Result<void>
RecoverKeyValueStorage(ara::core::InstanceSpecifier kvs) noexcept;

/** @req SWS_PER_00334 */
ara::core::Result<void>
ResetKeyValueStorage(ara::core::InstanceSpecifier kvs) noexcept;


/** @req SWS_PER_00339 */
class KeyValueStorage
{

 public:

    /** @req SWS_PER_00322 */
    KeyValueStorage(KeyValueStorage&& kvs) noexcept;

    /** @req SWS_PER_00324 */
    KeyValueStorage(const KeyValueStorage&) = delete;

    /** @req SWS_PER_00323 */
    KeyValueStorage& operator= (KeyValueStorage&& kvs) noexcept;

    /** @req SWS_PER_00325 */
    KeyValueStorage& operator= (const KeyValueStorage&) = delete;

    /** @req SWS_PER_00050 */
    ~KeyValueStorage() noexcept;

    /** @req SWS_PER_00042 */
    ara::core::Result<ara::core::Vector<ara::core::String>> GetAllKeys() const noexcept;

    /** @req SWS_PER_00043 */
    ara::core::Result<bool> HasKey(ara::core::StringView key) const noexcept;

    /** @req SWS_PER_00044 */
    template <class T>
    ara::core::Result<void> GetValue(ara::core::StringView key, T& value) const noexcept;

    /** @req SWS_PER_00332 */
    template <class T>
    ara::core::Result<T> GetValue(ara::core::StringView key) const noexcept;

    /** @req SWS_PER_00046 */
    template <class T>
    ara::core::Result<void> SetValue(ara::core::StringView key, const T& value) noexcept;

    /** @req SWS_PER_00047 */
    ara::core::Result<void> RemoveKey(ara::core::StringView key) noexcept;

    /** @req SWS_PER_00048 */
    ara::core::Result<void> RemoveAllKeys() noexcept;

    /** @req SWS_PER_00049 */
    ara::core::Result<void> SyncToStorage() const noexcept;

    /** @req SWS_PER_00365 */
    ara::core::Result<void> DiscardPendingChanges() const noexcept;
};

}  // namespace ara::per

/** @} */

