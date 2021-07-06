#pragma once
#include <Control/DefaultEffectItem.hpp>
#include <Effect/EffectFactory.hpp>
#include <Process/GenericProcessFactory.hpp>

#include <MyVfx/Process.hpp>

namespace MyVfx
{
using LayerFactory = Process::GenericDefaultLayerFactory<MyVfx::Model>;
}
