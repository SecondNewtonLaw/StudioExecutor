//
// Created by Dottik on 6/4/2024.
//
#pragma once

typedef int64_t (*Validator)(int64_t testAgainst, struct lua_State *testWith);

namespace RBX::Lua {
    struct ExtraSpace {
        struct Shared {
            int32_t threadCount;
            void *scriptContext;
            void *scriptVmState;
            char field_18[0x8];
            void *__intrusive_set_AllThreads;
        };

        [[maybe_unused]] char _0[8];
        [[maybe_unused]] char _8[8];
        [[maybe_unused]] char _10[8];
        struct RBX::Lua::ExtraSpace::Shared *sharedExtraSpace;
        [[maybe_unused]] char _20[8];
        Validator *CapabilitiesValidator;
        uint32_t identity;
        [[maybe_unused]] char _38[9];
        [[maybe_unused]] char _40[8];
        uint32_t capabilities;
        [[maybe_unused]] char _50[9];
        [[maybe_unused]] char _58[8];
        [[maybe_unused]] char _60[8];
        [[maybe_unused]] char _68[8];
        [[maybe_unused]] char _70[8];
        [[maybe_unused]] char _78[8];
        [[maybe_unused]] char _80[8];
        [[maybe_unused]] char _88[8];
        [[maybe_unused]] char _90[1];
        [[maybe_unused]] char _91[1];
        [[maybe_unused]] char _92[1];
        uint8_t taskStatus;
    };
}

namespace RBX::Security::Bypasses {
    void SetLuastateCapabilities(lua_State *L);

    // Sets capabilities on Lua closures, returns false if the operation fails (i.e: The closure is a C closure).
    bool SetClosureCapabilities(Closure *cl);
}

