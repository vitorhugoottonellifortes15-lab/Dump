// Undumped layouts (not exported by cs2-dumper schemas).
// Loaded at runtime by Updater / mod_offsets_fetch — do not bake these into the cheat sources.
#pragma once
#include <cstddef>

namespace cs2_dumper {
    namespace layout_extra {
        // CModelState: pointer to external bone cache (pos+quat entries).
        constexpr std::ptrdiff_t m_boneArrayInModelState = 0x80;
        // CModelState: pointer used by internal matrix bone path (hellcore).
        constexpr std::ptrdiff_t m_boneMatrixInModelState = 0x210;
    }
}
