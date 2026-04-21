#pragma once

#undef SCREEN_WIDTH
#undef SCREEN_HEIGHT
#define SCREEN_WIDTH GetDisplayWidth()
#define SCREEN_HEIGHT GetDisplayHeight()
#define MIN_MENU_WIDTH 800
#define MIN_MENU_HEIGHT 600
#define GAME_METRIC_UNITS 40.0f
#define STROKEW ImColor(10, 10, 10, 255)

#include <Windows.h>
#include <cstdint>
#include <Memory/Process.hpp>
#include <Memory/RemoteProcess.hpp>
#include <ImGui/imgui.h>
#include <string>

// Retorna dimensoes atuais considerando DPI/escala do monitor e viewport do ImGui
static inline int GetDisplayWidth()
{
    if (ImGui::GetCurrentContext())
    {
        const ImGuiIO& io = ImGui::GetIO();
        if (io.DisplaySize.x > 0.0f)
            return static_cast<int>(io.DisplaySize.x);
    }
    return GetSystemMetrics(SM_CXSCREEN);
}

static inline int GetDisplayHeight()
{
    if (ImGui::GetCurrentContext())
    {
        const ImGuiIO& io = ImGui::GetIO();
        if (io.DisplaySize.y > 0.0f)
            return static_cast<int>(io.DisplaySize.y);
    }
    return GetSystemMetrics(SM_CYSCREEN);
}

namespace Flags
{
    inline bool IsRunning = true;
    inline bool IsVisible = true;
    inline bool g_showWarningBox = false;
    inline bool g_showConsole = false;
    inline bool g_cs2Running = false;

    // App settings
    inline bool g_autoLoadConfig = false;
    inline std::string g_autoConfigName = ""; // e.g., "myconfig.json"

    // cheats flags
    inline bool enableTriggerbot = false;
    inline bool enableRCS = false;
    inline bool enableBhop = false;
    inline bool enableAntiflash = false;
    inline bool enableRadarHack = false;
    inline bool enableAimbot = false;
    inline bool enableJumpShot = false;
    inline bool enablePlayerEsp = false;
    inline bool enableC4Esp = false;
    inline bool enableWorldEsp = false;
    inline bool enableNoSky = false;
    inline bool enableNoSpread = false;
    inline bool enableTPV = false;
    inline bool enableMapView = false;
    inline bool enableFovChanger = false;
    inline bool enableSensiChanger = false;
    
    // Manual team override: 0 = none, 2 = T, 3 = CT
    inline int g_teamOverride = 0;
    // Donation/Unlock
    inline int g_donateClicks = 0;
    inline bool g_streamUnlock = false;
}

namespace Globals
{
    inline RemoteProcess* proc = nullptr;
}

namespace CS2
{
    inline DWORD ProcID = PM.GetProcessID(L"cs2.exe");
    inline DWORD SteamProcID = PM.GetProcessID(L"steam.exe");
    inline uintptr_t ClientDll = PM.GetModuleBaseAddress(ProcID, L"client.dll");
    inline uintptr_t Engine2Dll = PM.GetModuleBaseAddress(ProcID, L"engine2.dll");
    inline uintptr_t InputsystemDll = PM.GetModuleBaseAddress(ProcID, L"inputsystem.dll");
    inline uintptr_t MatchMakingDll = PM.GetModuleBaseAddress(ProcID, L"matchmaking.dll");
    inline uintptr_t SoundsystemDll = PM.GetModuleBaseAddress(ProcID, L"soundsystem.dll");
    inline uintptr_t ServerDll = PM.GetModuleBaseAddress(ProcID, L"server.dll");
    inline uintptr_t VPhysics2Dll = PM.GetModuleBaseAddress(ProcID, L"vphysics2.dll");
}

namespace Offsets
{
    // ===== BUTTON OFFSETS =====
    inline int dwForceAttack = 0x20488A0;
    inline int dwForceAttack2 = 0x2048930;
    inline int dwForceJump = 0x2048DB0;
    inline int dwForceBack = 0x2048B70;
    inline int dwForceDuck = 0x2048E40;
    inline int dwForceForward = 0x2048AE0;
    inline int dwForceLeft = 0x2048C00;
    inline int dwForceLookAtWeapon = 0x2338600;
    inline int dwForceReload = 0x2048810;
    inline int dwForceRight = 0x2048C90;
    inline int dwForceShowScores = 0x23384E0;
    inline int dwForceSprint = 0x2048780;
    inline int dwForceTurnLeft = 0x20489C0;
    inline int dwForceTurnRight = 0x2048A50;
    inline int dwForceUse = 0x2048D20;
    inline int dwForceZoom = 0x2338570;

    // ===== ENGINE2.DLL OFFSETS =====
    inline int dwBuildNumber = 0x60CC74;
    inline int dwNetworkGameClient = 0x90A0C0;
    inline int dwNetworkGameClient_clientTickCount = 0x378;
    inline int dwNetworkGameClient_deltaTick = 0x24C;
    inline int dwNetworkGameClient_isBackgroundMap = 0x2C141F;
    inline int dwNetworkGameClient_localPlayer = 0xF8;
    inline int dwNetworkGameClient_maxClients = 0x240;
    inline int dwNetworkGameClient_serverTickCount = 0x24C;
    inline int dwNetworkGameClient_signOnState = 0x230;
    inline int dwWindowHeight = 0x90E4EC;
    inline int dwWindowWidth = 0x90E4E8;

    // ===== CLIENT.DLL OFFSETS =====
    inline int dwCSGOInput = 0x23386E0;
    inline int dwEntityList = 0x24C9710;
    inline int dwLocalPlayerPawn = 0x204F630;
    inline int dwLocalPlayerController = 0x2302E80;
    inline int dwViewAngles = 0x2338D68;
    inline int dwViewMatrix = 0x23290D0;
    inline int dwSensitivity = 0x2321208;
    inline int dwSensitivity_sensitivity = 0x58;
    inline int dwGameRules = 0x19E9B80;
    inline int dwPlantedC4 = 0x2331848;
    inline int dwGlobalVars = 0x20444E8;
    inline int dwWeaponC4 = 0x22A1928;
    inline int dwGlowManager = 0x23207A8;
    inline int dwViewRender = 0x23292E8;
    inline int dwPrediction = 0x204F540;
    inline int dwGameEntitySystem = 0x24C9710;
    inline int dwGameEntitySystem_highestEntityIndex = 0x2090;

    // ===== MATCHMAKING.DLL OFFSETS =====
    inline int dwGameTypes = 0x1B0F80;

    // ===== INPUTSYSTEM.DLL OFFSETS =====
    inline int dwInputSystem = 0x42B50;

    // ===== SOUNDSYSTEM.DLL OFFSETS =====
    inline int dwSoundSystem = 0x512360;
    inline int dwSoundSystem_engineViewData = 0x7C;

    // ===== PERFECT CHAMS — RVA por build (0 = usar só assinatura). materialsystem2 / scenesystem. =====
    // IDA MCP materialsystem2.dll: sub_18003C090 (wrapper CMaterial2 + chama pipeline "Material Creation") — NÃO usar 0x651E0 (é debug font).
    inline std::uintptr_t dwMaterialSystem2_CreateMaterialRva = 0x3C090;
    // IDA MCP scenesystem.dll (Steam CS2): sub_180055BC0 — pattern legado bate 1x; RVA = 0x180055BC0 - imagebase
    inline std::uintptr_t dwSceneSystem_RenderObjectsRva = 0x55BC0;

    // ===== ENTITY OFFSETS =====
    inline int m_iTeamNum = 0x344;
    inline int m_iHealth = 0x2D0;
    inline int m_ArmorValue = 0x12DC;
    inline int m_hPlayerPawn = 0x8DC;
    inline int m_v_angle = 0x13B8;
    inline int m_hPawn = 0x4E0;
    inline int m_hController = 0xB80;
    inline int m_hObserverTarget = 0x4C;
    inline int m_pObserverServices = 0xA18;
    inline int m_flFlashBangTime = 0x13EC;
    inline int m_flFlashDuration = 0xCE4;
    inline int m_iIDEntIndex = 0x341C;
        inline int m_iShotsFired = 0x12A0;
        inline int m_flEmitSoundTime = 0x128C; // preenchido pelo updater (dump GitHub)
    inline int m_aimPunchAngle = 0xE78;
    inline int m_aimPunchCache = 0xE98;
    inline int m_vOldOrigin = 0x1390;
    inline int m_vecViewOffset = 0x730;
    inline int m_pGameSceneNode = 0x330;
    inline int m_bBombPlanted = 0x95F;
    inline int m_bBombDropped = 0xA40;
    inline int m_nBombSite = 0x950;
    inline int m_flC4Blow = 0x94C;
    inline int m_bIsScoped = 0x1284;
    inline int m_sSanitizedPlayerName = 0x858;
    inline int m_fFlags = 0x388;
    inline int m_vecAbsVelocity = 0x38C;
    inline int m_MoveType = 0x4;
    inline int m_pBulletServices = 0xD08;
    inline int m_angEyeAngles = 0x13B8;
    inline int m_totalHitsOnServer = 0x48;
    inline int m_vecAbsOrigin = 0xC8;
    inline int m_hOwnerEntity = 0x3E4;
    inline int m_iPing = 0x7F8;
    inline int m_bHasExploded = 0xCC4;
    inline int m_bBeingDefused = 0xCCC;
    inline int m_flDefuseLength = 0xCDC;
    inline int m_flDefuseCountDown = 0xCE0;
    inline int m_bWarmupPeriod = 0xD9;
    inline int m_bCTTimeOutActive = 0xE5;
    inline int m_bTerroristTimeOutActive = 0xE4;
    inline int m_Glow = 0x698;
    inline int m_glowColorOverride = 0x40;
    inline int m_bGlowing = 0x51;

    inline int m_pCameraServices = 0xA38;
    inline int m_hActivePostProcessingVolume = 0x1FC;
    inline int m_postProcessingVolume_flMinExposure = 0;
    inline int m_postProcessingVolume_flMaxExposure = 0;
    inline int m_iFOV = 0x178;
    inline int m_iFOVStart = 0x17C;
    inline int m_flFOVTime = 0x180;
    inline int m_flFOVRate = 0x184;
    inline int m_iDesiredFOV = 0x70C;
    inline int m_bDormant = 0xE7;
    inline int m_pWeaponServices = 0xA00;
    inline int m_pMovementServices = 0xA40;
    inline int m_flDuckAmount = 0x3E4;
    inline int m_bInLanding = 0x1518;
    inline int m_pClippingWeapon = 0;
    inline int m_hMyWeapons = 0x48;
    inline int kEntityListEntryStride = 0x70;
    inline int m_AttributeManager = 0x960;
    inline int m_AttributeManager_EconEntity = 0x960;
    inline int m_Item = 0x50;
    inline int m_AttributeList = 0x70;
    inline int m_Attributes = 0x8;
    inline int m_iItemDefinitionIndex = 0x38;
    inline int m_iEntityQuality = 0x3C;
    inline int m_iItemIDHigh = 0x50;
    inline int m_iItemIDLow = 0x54;
    inline int m_iAccountID = 0x58;
    inline int m_MeshGroupMask = 0x1A8;
    inline int m_OriginalOwnerXuidLow = 0xC50;
    inline int m_nFallbackStatTrak = 0xC64;
    inline int m_nFallbackPaintKit = 0xC58;
    inline int m_nFallbackSeed = 0xC5C;
    inline int m_flFallbackWear = 0xC60;
    inline int m_pViewModelServices = 0x1368;
    inline int m_EconGloves = 0xF70;
    inline int m_bNeedToReApplyGloves = 0x1695;
    inline int m_hViewModel = 0x40;
    inline int m_bSpotted = 0x8;
    inline int m_bSpottedByMask = 0xC;
    inline int m_entitySpottedState = 0x9E0;
    inline int m_iPendingTeamNum = 0x810;
    inline int m_iOldTeam = 0x168C;
    inline int m_iCoachingTeam = 0x838;
    inline int m_bEverPlayedOnTeam = 0x81C;
    inline int m_nodeToWorld = 0x10;
    /** Cliente: C_BaseModelEntity::m_Collision (client_dll). Era 0x5E8 (server) e quebrava AABB em drops. */
    inline int m_Collision = 0xD28;
    inline int gv_curtime = 0x10;
    inline int gv_interval_per_tick = 0x14;
    /** CGlobalVarsBase::m_map_name indirection (ptr to std::string), then MSVC std::string layout */
    inline int gv_map_name = 0x188;
    inline int m_hActiveWeapon = 0x60;
    inline int m_pWeaponVData = 0x390;
    inline int m_iClip1 = 0xC80;
    inline int m_iMaxClip1 = 0x4D0;
    inline int m_flCrosshairDistance = 0x1790;
    inline int m_fAccuracyPenalty = 0xD48;
    inline int m_flTurningInaccuracy = 0xD44;
    inline int m_flPostponeFireReadyFrac = 0xD64;
    inline int m_weaponMode = 0xD30;
    inline int v_m_flMaxSpeed = 0x7CC;
    inline int v_m_flInaccuracyCrouch = 0x760;
    inline int v_m_flInaccuracyStand = 0x768;
    inline int v_m_flInaccuracyJump = 0x770;
    inline int v_m_flInaccuracyLand = 0x778;
    inline int v_m_flInaccuracyLadder = 0x780;
    inline int v_m_flInaccuracyFire = 0x788;
    inline int v_m_flInaccuracyMove = 0x790;
    inline int m_bIsLocalPlayerController = 0x780;
    inline int m_pBot = 0x12C8;
    inline int m_isEnemyVisible = 0x59F4;
    inline int m_modelState = 0x130;
    inline int m_flSimulationTime = 0x32C;
    inline int dwGameTypes_mapName = 0x120;
}

// Funcao utilitaria para focar na janela do CS2
inline void FocusCS2Window()
{
    HWND cs2Window = FindWindowW(nullptr, L"Counter-Strike 2");
    if (cs2Window != nullptr)
    {
        if (IsIconic(cs2Window))
        {
            ShowWindow(cs2Window, SW_RESTORE);
        }
        SetForegroundWindow(cs2Window);
        SetFocus(cs2Window);
        BringWindowToTop(cs2Window);
    }
}
