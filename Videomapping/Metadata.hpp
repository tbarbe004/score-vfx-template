#pragma once
#include <Process/ProcessMetadata.hpp>

namespace Videomapping
{
class Model;
}

PROCESS_METADATA(
    ,
    Videomapping::Model,
    "16a7d649-4878-4496-90ea-8c1a8c7cc408",
    "Videomapping",                           // Internal name
    "Videomapping",                           // Pretty name
    Process::ProcessCategory::Visual,  // Category
    "GFX",                             // Category
    "My VFX",                          // Description
    "ossia team",                      // Author
    (QStringList{"shader", "gfx"}),    // Tags
    {},                                // Inputs
    {},                                // Outputs
    Process::ProcessFlags::SupportsAll // Flags
)
