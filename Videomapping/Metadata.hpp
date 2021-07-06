#pragma once
#include <Process/ProcessMetadata.hpp>

namespace MyVfx
{
class Model;
}

PROCESS_METADATA(
    ,
    MyVfx::Model,
    "16a7d649-4878-4496-90ea-8c1a8c7cc408",
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
