﻿#include "dllmain.hpp"

SafetyHookInline Dimension_Dimension_Hook;

void* Dimension_Dimension(void* self, void* a2, int dimensionID, HeightRange HeightRange, void* a5, std::string* dimName)
{
    // Set max height to 2048 blocks
    HeightRange.mMaxHeight = 2048;
    return Dimension_Dimension_Hook.fastcall<void*>(self, a2, dimensionID, HeightRange, a5, dimName);
}

// Ran when the mod is loaded into the game by AmethystRuntime
ModFunction void Initialize(AmethystContext* ctx) 
{
    // Hook dim ctor
    ctx->mHookManager.RegisterFunction<Dimension_Dimension>("48 89 5C 24 ? 48 89 74 24 ? 48 89 7C 24 ? 55 41 54 41 55 41 56 41 57 48 8D 6C 24 ? 48 81 EC ? ? ? ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 45 ? 41 8B F9 41 8B D8");
    ctx->mHookManager.CreateHook<&Dimension_Dimension>(Dimension_Dimension_Hook, Dimension_Dimension);
}
