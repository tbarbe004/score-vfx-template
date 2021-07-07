#pragma once
#include <Control/DefaultEffectItem.hpp>
#include <Effect/EffectFactory.hpp>
#include <Process/GenericProcessFactory.hpp>

#include <Videomapping/Process.hpp>

namespace Videomapping
{
using LayerFactory = Process::GenericDefaultLayerFactory<Videomapping::Model>;
}
