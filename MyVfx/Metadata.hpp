#pragma once
#include <Process/ProcessMetadata.hpp>

namespace MyVfx
{
class Model;
}

PROCESS_METADATA(
    ,
    MyVfx::Model,
    "00000000-0000-0000-0000-000000000000",
    "MyVfx",                           // Internal name
    "MyVfx",                           // Pretty name
    Process::ProcessCategory::Visual,  // Category
    "GFX",                             // Category
    "My VFX",                          // Description
    "ossia team",                      // Author
    (QStringList{"shader", "gfx"}),    // Tags
    {},                                // Inputs
    {},                                // Outputs
    Process::ProcessFlags::SupportsAll // Flags
)
