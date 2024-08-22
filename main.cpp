#include <iostream>

// clang-format off

#include <windows.h>
#include <powrprof.h>

// clang-format on

int main() {
    SYSTEM_POWER_STATUS spsPwr;
    GUID *ActivePolicyGuid;

    while (1) {
        GetSystemPowerStatus(&spsPwr);
        PowerGetActiveScheme(nullptr, &ActivePolicyGuid);

        if (ActivePolicyGuid->Data1 == 2448487014 && spsPwr.ACLineStatus == 0)
            std::system("powercfg /S 0322c294-a9d6-4ae6-9c45-9ee60ab1a56b");
        else if (ActivePolicyGuid->Data1 != 2448487014 && spsPwr.ACLineStatus == 1)
            std::system("powercfg /S 91f0f266-a0a3-4274-93d6-7c9bc8fa5364");

        LocalFree(ActivePolicyGuid);
        Sleep(10000);
    }

    return 0;
}
