/*! \file imgui_style.h
 *  \brief Enter description here.
 *  \author Georgi Gerganov
 */

#pragma once

#include "imgui.h"

namespace ImGui {

    enum StyleId {
        IMGUI_STYLE_DEFAULT,
        IMGUI_STYLE_TEAL_AND_ORANGE,
        IMGUI_STYLE_DARK,
        IMGUI_STYLE_LIGHT,
        IMGUI_STYLE_GREEN,
        IMGUI_STYLE_DANHIEZ_LIGHT,
        IMGUI_STYLE_MONOCHROME,
        IMGUI_STYLE_R0,
        IMGUI_STYLE_GRAY_AND_ORANGE,
        IMGUI_STYLE_HERCULESUI,
    };

    template <StyleId>
        static bool applyStyle();

    template <>
        bool applyStyle<IMGUI_STYLE_DEFAULT>() {
            ImGui::StyleColorsClassic();
            return true;
        }

    template <>
        bool applyStyle<IMGUI_STYLE_TEAL_AND_ORANGE>() {
            ImGuiStyle & style = ImGui::GetStyle();

            style.WindowPadding = ImVec2(8, 8);
            style.WindowRounding = 0.0f;
            style.FramePadding = ImVec2(4, 3);
            style.FrameRounding = 0.0f;
            style.ItemSpacing = ImVec2(8, 4);
            style.ItemInnerSpacing = ImVec2(4, 4);
            style.IndentSpacing = 21.0f;
            style.ScrollbarSize = 16.0f;
            style.ScrollbarRounding = 9.0f;
            style.GrabMinSize = 10.0f;
            style.GrabRounding = 3.0f;

            style.Colors[ImGuiCol_Text]                  = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
            style.Colors[ImGuiCol_TextDisabled]          = ImVec4(0.24f, 0.41f, 0.41f, 1.00f);
            style.Colors[ImGuiCol_WindowBg]              = ImVec4(0.08f, 0.08f, 0.08f, 0.94f);
            style.Colors[ImGuiCol_ChildWindowBg]         = ImVec4(0.07f, 0.07f, 0.09f, 1.00f);
            style.Colors[ImGuiCol_PopupBg]               = ImVec4(0.07f, 0.07f, 0.09f, 1.00f);
            style.Colors[ImGuiCol_Border]                = ImVec4(0.31f, 0.31f, 0.31f, 0.71f);
            style.Colors[ImGuiCol_BorderShadow]          = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
            style.Colors[ImGuiCol_FrameBg]               = ImVec4(0.00f, 0.39f, 0.39f, 0.39f);
            style.Colors[ImGuiCol_FrameBgHovered]        = ImVec4(0.26f, 1.00f, 1.00f, 0.39f);
            style.Colors[ImGuiCol_FrameBgActive]         = ImVec4(0.00f, 0.78f, 0.00f, 1.00f);
            style.Colors[ImGuiCol_TitleBg]               = ImVec4(0.00f, 0.50f, 0.50f, 0.70f);
            style.Colors[ImGuiCol_TitleBgCollapsed]      = ImVec4(0.00f, 0.50f, 0.50f, 1.00f);
            style.Colors[ImGuiCol_TitleBgActive]         = ImVec4(0.00f, 0.70f, 0.70f, 1.00f);
            style.Colors[ImGuiCol_MenuBarBg]             = ImVec4(0.00f, 0.70f, 0.70f, 1.00f);
            style.Colors[ImGuiCol_ScrollbarBg]           = ImVec4(0.10f, 0.27f, 0.27f, 1.00f);
            style.Colors[ImGuiCol_ScrollbarGrab]         = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
            style.Colors[ImGuiCol_ScrollbarGrabHovered]  = ImVec4(0.26f, 1.00f, 1.00f, 0.39f);
            style.Colors[ImGuiCol_ScrollbarGrabActive]   = ImVec4(0.00f, 0.78f, 0.00f, 1.00f);
            //style.Colors[ImGuiCol_ComboBg]               = ImVec4(0.00f, 0.39f, 0.39f, 1.00f);
            style.Colors[ImGuiCol_CheckMark]             = ImVec4(0.80f, 0.80f, 0.83f, 0.39f);
            style.Colors[ImGuiCol_SliderGrab]            = ImVec4(0.80f, 0.80f, 0.83f, 0.39f);
            style.Colors[ImGuiCol_SliderGrabActive]      = ImVec4(0.00f, 0.78f, 0.00f, 1.00f);
            style.Colors[ImGuiCol_Button]                = ImVec4(0.13f, 0.55f, 0.55f, 1.00f);
            style.Colors[ImGuiCol_ButtonHovered]         = ImVec4(0.61f, 1.00f, 0.00f, 0.51f);
            style.Colors[ImGuiCol_ButtonActive]          = ImVec4(0.00f, 0.78f, 0.00f, 1.00f);
            style.Colors[ImGuiCol_Header]                = ImVec4(0.79f, 0.51f, 0.00f, 0.51f);
            style.Colors[ImGuiCol_HeaderHovered]         = ImVec4(0.79f, 0.51f, 0.00f, 0.67f);
            style.Colors[ImGuiCol_HeaderActive]          = ImVec4(0.79f, 0.51f, 0.00f, 0.67f);
            style.Colors[ImGuiCol_Column]                = ImVec4(0.79f, 0.51f, 0.00f, 0.67f);
            style.Colors[ImGuiCol_ColumnHovered]         = ImVec4(0.25f, 1.00f, 0.00f, 1.00f);
            style.Colors[ImGuiCol_ColumnActive]          = ImVec4(0.79f, 0.51f, 0.00f, 0.67f);
            style.Colors[ImGuiCol_ResizeGrip]            = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
            style.Colors[ImGuiCol_ResizeGripHovered]     = ImVec4(0.26f, 1.00f, 1.00f, 0.39f);
            style.Colors[ImGuiCol_ResizeGripActive]      = ImVec4(0.00f, 0.78f, 0.00f, 1.00f);
            //style.Colors[ImGuiCol_CloseButton]           = ImVec4(0.40f, 0.39f, 0.38f, 0.16f);
            //style.Colors[ImGuiCol_CloseButtonHovered]    = ImVec4(0.26f, 1.00f, 1.00f, 0.39f);
            //style.Colors[ImGuiCol_CloseButtonActive]     = ImVec4(0.79f, 0.51f, 0.00f, 0.67f);
            style.Colors[ImGuiCol_PlotLines]             = ImVec4(1.00f, 0.65f, 0.38f, 0.67f);
            style.Colors[ImGuiCol_PlotLinesHovered]      = ImVec4(0.25f, 1.00f, 0.00f, 1.00f);
            style.Colors[ImGuiCol_PlotHistogram]         = ImVec4(1.00f, 0.65f, 0.38f, 0.67f);
            style.Colors[ImGuiCol_PlotHistogramHovered]  = ImVec4(0.25f, 1.00f, 0.00f, 1.00f);
            style.Colors[ImGuiCol_TextSelectedBg]        = ImVec4(0.25f, 1.00f, 0.00f, 0.43f);
            style.Colors[ImGuiCol_ModalWindowDarkening]  = ImVec4(1.00f, 0.98f, 0.95f, 0.78f);

            return true;
        }

    template <>
        bool applyStyle<IMGUI_STYLE_DARK>() {
            ImGui::StyleColorsDark();
            return true;
        }

    template <>
        bool applyStyle<IMGUI_STYLE_LIGHT>() {
            ImGui::StyleColorsLight();
            return true;
        }

    template <>
        bool applyStyle<IMGUI_STYLE_GREEN>() {
            ImGuiStyle & style = ImGui::GetStyle();

            style.WindowMinSize = ImVec2(115, 20);
            style.FramePadding = ImVec2(4, 2);
            style.ItemSpacing = ImVec2(6, 2);
            style.ItemInnerSpacing = ImVec2(6, 4);
            style.Alpha = 1.0f;
            style.WindowRounding = 4.0f;
            style.WindowPadding = ImVec2(9, 8);
            style.FrameRounding = 2.0f;
            style.IndentSpacing = 6.0f;
            style.ItemInnerSpacing = ImVec2(2, 4);
            style.WindowTitleAlign = ImVec2(0.5, 0);
            style.ColumnsMinSpacing = 50.0f;
            style.GrabMinSize = 20.0f;
            style.GrabRounding = 20.0f;
            style.ScrollbarSize = 12.0f;
            style.ScrollbarRounding = 16.0f;

            style.Colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
            style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.86f, 0.93f, 0.89f, 1.00f);
            style.Colors[ImGuiCol_WindowBg] = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
            style.Colors[ImGuiCol_ChildWindowBg] = ImVec4(0.20f, 0.22f, 0.27f, 1.00f);
            style.Colors[ImGuiCol_PopupBg] = ImVec4(0.47f, 0.77f, 0.83f, 1.00f);
            style.Colors[ImGuiCol_Border] = ImVec4(0.31f, 0.31f, 1.00f, 0.10f);
            style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
            style.Colors[ImGuiCol_FrameBg] = ImVec4(0.00f, 0.32f, 0.27f, 1.00f);
            style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.11f, 0.74f, 0.00f, 1.00f);
            style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.07f, 0.70f, 0.01f, 1.00f);
            style.Colors[ImGuiCol_TitleBg] = ImVec4(0.00f, 0.43f, 0.24f, 1.00f);
            style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.20f, 0.22f, 0.27f, 1.00f);
            style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.07f, 0.67f, 0.01f, 1.00f);
            style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.20f, 0.22f, 0.27f, 1.00f);
            style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.20f, 0.22f, 0.27f, 1.00f);
            style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.00f, 0.43f, 0.24f, 1.00f);
            style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.19f, 0.76f, 0.00f, 1.00f);
            style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.03f, 0.70f, 0.06f, 1.00f);
            //style.Colors[ImGuiCol_ComboBg] = ImVec4(0.20f, 0.20f, 0.20f, 1.00f);
            style.Colors[ImGuiCol_CheckMark] = ImVec4(0.00f, 0.71f, 0.39f, 1.00f);
            style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.02f, 0.59f, 0.38f, 1.00f);
            style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.00f, 0.49f, 0.51f, 1.00f);
            style.Colors[ImGuiCol_Button] = ImVec4(0.00f, 0.43f, 0.24f, 1.00f);
            style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.08f, 0.77f, 0.03f, 1.00f);
            style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.08f, 0.72f, 0.00f, 1.00f);
            style.Colors[ImGuiCol_Header] = ImVec4(0.11f, 0.64f, 0.00f, 1.00f);
            style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.03f, 0.70f, 0.01f, 1.00f);
            style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.05f, 0.72f, 0.01f, 1.00f);
            style.Colors[ImGuiCol_Column] = ImVec4(0.14f, 0.16f, 0.19f, 1.00f);
            style.Colors[ImGuiCol_ColumnHovered] = ImVec4(0.08f, 0.69f, 0.02f, 1.00f);
            style.Colors[ImGuiCol_ColumnActive] = ImVec4(0.00f, 0.76f, 0.04f, 1.00f);
            style.Colors[ImGuiCol_ResizeGrip] = ImVec4(0.47f, 0.77f, 0.83f, 1.00f);
            style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.00f, 0.55f, 0.12f, 1.00f);
            style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.00f, 0.71f, 0.01f, 1.00f);
            //style.Colors[ImGuiCol_CloseButton] = ImVec4(0.86f, 0.93f, 0.89f, 1.00f);
            //style.Colors[ImGuiCol_CloseButtonHovered] = ImVec4(0.86f, 0.93f, 0.89f, 1.00f);
            //style.Colors[ImGuiCol_CloseButtonActive] = ImVec4(0.86f, 0.93f, 0.89f, 1.00f);
            style.Colors[ImGuiCol_PlotLines] = ImVec4(0.86f, 0.93f, 0.89f, 1.00f);
            style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.05f, 0.64f, 0.01f, 1.00f);
            style.Colors[ImGuiCol_PlotHistogram] = ImVec4(0.86f, 0.93f, 0.89f, 1.00f);
            style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(0.04f, 0.70f, 0.02f, 1.00f);
            style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.02f, 0.57f, 0.00f, 1.00f);
            style.Colors[ImGuiCol_ModalWindowDarkening] = ImVec4(0.20f, 0.22f, 0.27f, 1.00f);

            return true;
        }

    template <>
        bool applyStyle<IMGUI_STYLE_DANHIEZ_LIGHT>() {
            ImGuiStyle& style = ImGui::GetStyle();

            // light style from Pacôme Danhiez (user itamago) https://github.com/ocornut/imgui/pull/511#issuecomment-175719267
            style.Alpha = 1.0f;
            style.FrameRounding = 3.0f;
            style.Colors[ImGuiCol_Text]                  = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
            style.Colors[ImGuiCol_TextDisabled]          = ImVec4(0.60f, 0.60f, 0.60f, 1.00f);
            style.Colors[ImGuiCol_WindowBg]              = ImVec4(0.94f, 0.94f, 0.94f, 0.94f);
            style.Colors[ImGuiCol_ChildWindowBg]         = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
            style.Colors[ImGuiCol_PopupBg]               = ImVec4(1.00f, 1.00f, 1.00f, 0.94f);
            style.Colors[ImGuiCol_Border]                = ImVec4(0.00f, 0.00f, 0.00f, 0.10f);
            style.Colors[ImGuiCol_BorderShadow]          = ImVec4(1.00f, 1.00f, 1.00f, 0.00f);
            style.Colors[ImGuiCol_FrameBg]               = ImVec4(1.00f, 1.00f, 1.00f, 0.94f);
            style.Colors[ImGuiCol_FrameBgHovered]        = ImVec4(0.26f, 0.59f, 0.98f, 0.40f);
            style.Colors[ImGuiCol_FrameBgActive]         = ImVec4(0.26f, 0.59f, 0.98f, 0.67f);
            style.Colors[ImGuiCol_TitleBg]               = ImVec4(0.96f, 0.96f, 0.96f, 1.00f);
            style.Colors[ImGuiCol_TitleBgCollapsed]      = ImVec4(1.00f, 1.00f, 1.00f, 0.51f);
            style.Colors[ImGuiCol_TitleBgActive]         = ImVec4(0.82f, 0.82f, 0.82f, 1.00f);
            style.Colors[ImGuiCol_MenuBarBg]             = ImVec4(0.86f, 0.86f, 0.86f, 1.00f);
            style.Colors[ImGuiCol_ScrollbarBg]           = ImVec4(0.98f, 0.98f, 0.98f, 0.53f);
            style.Colors[ImGuiCol_ScrollbarGrab]         = ImVec4(0.69f, 0.69f, 0.69f, 1.00f);
            style.Colors[ImGuiCol_ScrollbarGrabHovered]  = ImVec4(0.59f, 0.59f, 0.59f, 1.00f);
            style.Colors[ImGuiCol_ScrollbarGrabActive]   = ImVec4(0.49f, 0.49f, 0.49f, 1.00f);
            //style.Colors[ImGuiCol_ComboBg]               = ImVec4(0.86f, 0.86f, 0.86f, 0.99f);
            style.Colors[ImGuiCol_CheckMark]             = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
            style.Colors[ImGuiCol_SliderGrab]            = ImVec4(0.24f, 0.52f, 0.88f, 1.00f);
            style.Colors[ImGuiCol_SliderGrabActive]      = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
            style.Colors[ImGuiCol_Button]                = ImVec4(0.26f, 0.59f, 0.98f, 0.40f);
            style.Colors[ImGuiCol_ButtonHovered]         = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
            style.Colors[ImGuiCol_ButtonActive]          = ImVec4(0.06f, 0.53f, 0.98f, 1.00f);
            style.Colors[ImGuiCol_Header]                = ImVec4(0.26f, 0.59f, 0.98f, 0.31f);
            style.Colors[ImGuiCol_HeaderHovered]         = ImVec4(0.26f, 0.59f, 0.98f, 0.80f);
            style.Colors[ImGuiCol_HeaderActive]          = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
            style.Colors[ImGuiCol_Column]                = ImVec4(0.39f, 0.39f, 0.39f, 1.00f);
            style.Colors[ImGuiCol_ColumnHovered]         = ImVec4(0.26f, 0.59f, 0.98f, 0.78f);
            style.Colors[ImGuiCol_ColumnActive]          = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
            style.Colors[ImGuiCol_ResizeGrip]            = ImVec4(1.00f, 1.00f, 1.00f, 0.50f);
            style.Colors[ImGuiCol_ResizeGripHovered]     = ImVec4(0.26f, 0.59f, 0.98f, 0.67f);
            style.Colors[ImGuiCol_ResizeGripActive]      = ImVec4(0.26f, 0.59f, 0.98f, 0.95f);
            //style.Colors[ImGuiCol_CloseButton]           = ImVec4(0.59f, 0.59f, 0.59f, 0.50f);
            //style.Colors[ImGuiCol_CloseButtonHovered]    = ImVec4(0.98f, 0.39f, 0.36f, 1.00f);
            //style.Colors[ImGuiCol_CloseButtonActive]     = ImVec4(0.98f, 0.39f, 0.36f, 1.00f);
            style.Colors[ImGuiCol_PlotLines]             = ImVec4(0.39f, 0.39f, 0.39f, 1.00f);
            style.Colors[ImGuiCol_PlotLinesHovered]      = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
            style.Colors[ImGuiCol_PlotHistogram]         = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
            style.Colors[ImGuiCol_PlotHistogramHovered]  = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
            style.Colors[ImGuiCol_TextSelectedBg]        = ImVec4(0.26f, 0.59f, 0.98f, 0.35f);
            style.Colors[ImGuiCol_ModalWindowDarkening]  = ImVec4(0.20f, 0.20f, 0.20f, 0.35f);

            return true;
        }

    template <>
        bool applyStyle<IMGUI_STYLE_MONOCHROME>() {
            ImGuiStyle& style = ImGui::GetStyle();
            style.Alpha = 1.0;
            //style.ChildWindowRounding = 3;
            style.WindowRounding = 3;
            style.GrabRounding = 1;
            style.GrabMinSize = 20;
            style.FrameRounding = 3;


            style.Colors[ImGuiCol_Text] = ImVec4(0.00f, 1.00f, 1.00f, 1.00f);
            style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.00f, 0.40f, 0.41f, 1.00f);
            style.Colors[ImGuiCol_WindowBg] = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
            style.Colors[ImGuiCol_ChildWindowBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
            style.Colors[ImGuiCol_Border] = ImVec4(0.00f, 1.00f, 1.00f, 0.10f);
            style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
            style.Colors[ImGuiCol_FrameBg] = ImVec4(0.44f, 0.80f, 0.80f, 0.18f);
            style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.44f, 0.80f, 0.80f, 0.27f);
            style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.44f, 0.81f, 0.86f, 0.66f);
            style.Colors[ImGuiCol_TitleBg] = ImVec4(0.14f, 0.18f, 0.21f, 0.73f);
            style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.00f, 0.00f, 0.54f);
            style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.00f, 1.00f, 1.00f, 0.27f);
            style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.20f);
            style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.22f, 0.29f, 0.30f, 0.71f);
            style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.00f, 1.00f, 1.00f, 0.44f);
            style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.00f, 1.00f, 1.00f, 0.74f);
            style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.00f, 1.00f, 1.00f, 1.00f);
            //style.Colors[ImGuiCol_ComboBg] = ImVec4(0.16f, 0.24f, 0.22f, 0.60f);
            style.Colors[ImGuiCol_CheckMark] = ImVec4(0.00f, 1.00f, 1.00f, 0.68f);
            style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.00f, 1.00f, 1.00f, 0.36f);
            style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.00f, 1.00f, 1.00f, 0.76f);
            style.Colors[ImGuiCol_Button] = ImVec4(0.00f, 0.65f, 0.65f, 0.46f);
            style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.01f, 1.00f, 1.00f, 0.43f);
            style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.00f, 1.00f, 1.00f, 0.62f);
            style.Colors[ImGuiCol_Header] = ImVec4(0.00f, 1.00f, 1.00f, 0.33f);
            style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.00f, 1.00f, 1.00f, 0.42f);
            style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.00f, 1.00f, 1.00f, 0.54f);
            style.Colors[ImGuiCol_Column] = ImVec4(0.00f, 0.50f, 0.50f, 0.33f);
            style.Colors[ImGuiCol_ColumnHovered] = ImVec4(0.00f, 0.50f, 0.50f, 0.47f);
            style.Colors[ImGuiCol_ColumnActive] = ImVec4(0.00f, 0.70f, 0.70f, 1.00f);
            style.Colors[ImGuiCol_ResizeGrip] = ImVec4(0.00f, 1.00f, 1.00f, 0.54f);
            style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.00f, 1.00f, 1.00f, 0.74f);
            style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.00f, 1.00f, 1.00f, 1.00f);
            //style.Colors[ImGuiCol_CloseButton] = ImVec4(0.00f, 0.78f, 0.78f, 0.35f);
            //style.Colors[ImGuiCol_CloseButtonHovered] = ImVec4(0.00f, 0.78f, 0.78f, 0.47f);
            //style.Colors[ImGuiCol_CloseButtonActive] = ImVec4(0.00f, 0.78f, 0.78f, 1.00f);
            style.Colors[ImGuiCol_PlotLines] = ImVec4(0.00f, 1.00f, 1.00f, 1.00f);
            style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.00f, 1.00f, 1.00f, 1.00f);
            style.Colors[ImGuiCol_PlotHistogram] = ImVec4(0.00f, 1.00f, 1.00f, 1.00f);
            style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(0.00f, 1.00f, 1.00f, 1.00f);
            style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.00f, 1.00f, 1.00f, 0.22f);
            //style.Colors[ImGuiCol_TooltipBg] = ImVec4(0.00f, 0.13f, 0.13f, 0.90f);
            style.Colors[ImGuiCol_ModalWindowDarkening] = ImVec4(0.04f, 0.10f, 0.09f, 0.51f);

            return true;
        }

    template <>
        bool applyStyle<IMGUI_STYLE_R0>() {
            ImGuiStyle& style = ImGui::GetStyle();

            style.Colors[ImGuiCol_Text] = ImVec4(0.90f, 0.90f, 0.90f, 0.93f);
            style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.60f, 0.60f, 0.60f, 0.68f);
            style.Colors[ImGuiCol_WindowBg] = ImVec4(0.16f, 0.16f, 0.16f, 0.96f);
            style.Colors[ImGuiCol_PopupBg] = ImVec4(0.10f, 0.10f, 0.10f, 0.94f);
            style.Colors[ImGuiCol_Border] = ImVec4(0.34f, 0.33f, 0.34f, 0.10f);
            style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
            style.Colors[ImGuiCol_FrameBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.33f);
            style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.80f, 0.80f, 1.00f, 0.40f);
            style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.50f, 0.58f, 0.85f, 0.65f);
            style.Colors[ImGuiCol_TitleBg] = ImVec4(0.40f, 0.40f, 0.39f, 0.80f);
            style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.22f, 0.39f, 0.73f, 0.52f);
            style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.13f, 0.41f, 0.71f, 1.00f);
            style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.30f, 0.31f, 0.31f, 0.80f);
            style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.20f, 0.25f, 0.30f, 0.00f);
            style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.40f, 0.40f, 0.40f, 0.39f);
            style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.40f, 0.40f, 0.40f, 0.59f);
            style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.50f, 0.50f, 0.50f, 0.72f);
            //style.Colors[ImGuiCol_ComboBg] = ImVec4(0.20f, 0.20f, 0.20f, 1.00f);
            style.Colors[ImGuiCol_CheckMark] = ImVec4(0.27f, 0.58f, 1.00f, 1.00f);
            style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.20f, 0.57f, 1.00f, 0.84f);
            style.Colors[ImGuiCol_Button] = ImVec4(0.27f, 0.58f, 1.00f, 0.78f);
            style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.37f, 0.64f, 1.00f, 0.94f);
            style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.27f, 0.44f, 1.00f, 1.00f);
            style.Colors[ImGuiCol_Header] = ImVec4(0.49f, 0.49f, 0.49f, 0.46f);
            style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.45f, 0.45f, 0.50f, 0.49f);
            style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.53f, 0.53f, 0.57f, 0.75f);
            style.Colors[ImGuiCol_ColumnHovered] = ImVec4(0.60f, 0.60f, 0.70f, 1.00f);
            style.Colors[ImGuiCol_ColumnActive] = ImVec4(0.70f, 0.70f, 0.90f, 1.00f);
            style.Colors[ImGuiCol_ResizeGrip] = ImVec4(1.00f, 1.00f, 1.00f, 0.47f);
            style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.78f, 0.76f, 1.00f, 1.00f);
            //style.Colors[ImGuiCol_CloseButton] = ImVec4(0.50f, 0.50f, 0.50f, 0.89f);
            //style.Colors[ImGuiCol_CloseButtonHovered] = ImVec4(0.70f, 0.70f, 0.71f, 0.60f);
            style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.27f, 0.54f, 1.00f, 0.47f);
            style.Colors[ImGuiCol_PlotHistogram] = ImVec4(0.24f, 0.58f, 1.00f, 1.00f);
            style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(0.23f, 0.47f, 1.00f, 1.00f);
            style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.16f, 0.37f, 0.98f, 0.75f);

            return true;
        }

    template <>
        bool applyStyle<IMGUI_STYLE_GRAY_AND_ORANGE>() {
            auto& style = ImGui::GetStyle();

            style.Alpha = 1.0f;
            style.WindowPadding = ImVec2(8, 8);
            style.WindowMinSize = ImVec2(32, 32);
            style.WindowRounding = 0.0f;
            //style.WindowTitleAlign = ImGuiAlign_Left;
            //style.ChildWindowRounding = 0.0f;
            style.FramePadding = ImVec2(4, 3);
            style.FrameRounding = 0.0f;
            style.ItemSpacing = ImVec2(8, 4);
            style.ItemInnerSpacing = ImVec2(4, 4);
            style.TouchExtraPadding = ImVec2(0, 0);
            style.IndentSpacing = 21.0f;
            style.ColumnsMinSpacing = 6.0f;
            style.ScrollbarSize = 16.0f;
            style.ScrollbarRounding = 9.0f;
            style.GrabMinSize = 10.0f;
            style.GrabRounding = 0.0f;
            style.DisplayWindowPadding = ImVec2(22, 22);
            style.DisplaySafeAreaPadding = ImVec2(4, 4);
            style.AntiAliasedLines = true;
            //style.AntiAliasedShapes = true;
            style.CurveTessellationTol = 1.25f;

            style.Colors[ImGuiCol_Text] = ImVec4(0.90f, 0.90f, 0.90f, 1.00f);
            style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.60f, 0.60f, 0.60f, 1.00f);
            style.Colors[ImGuiCol_WindowBg] = ImVec4(0.12f, 0.12f, 0.12f, 1.00f);
            style.Colors[ImGuiCol_ChildWindowBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
            style.Colors[ImGuiCol_PopupBg] = ImVec4(0.05f, 0.05f, 0.10f, 1.00f);
            style.Colors[ImGuiCol_Border] = ImVec4(0.25f, 0.25f, 0.25f, 1.00f);
            style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
            style.Colors[ImGuiCol_FrameBg] = ImVec4(0.25f, 0.25f, 0.25f, 1.00f);
            style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(1.00f, 0.47f, 0.00f, 1.00f);
            style.Colors[ImGuiCol_FrameBgActive] = ImVec4(1.00f, 0.47f, 0.00f, 1.00f);
            style.Colors[ImGuiCol_TitleBg] = ImVec4(0.25f, 0.25f, 0.25f, 1.00f);
            style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.12f, 0.12f, 0.12f, 1.00f);
            style.Colors[ImGuiCol_TitleBgActive] = ImVec4(1.00f, 0.47f, 0.00f, 1.00f);
            style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.25f, 0.25f, 0.25f, 1.00f);
            style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.25f, 0.25f, 0.25f, 1.00f);
            style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.40f, 0.40f, 0.40f, 1.00f);
            style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.40f, 0.40f, 0.40f, 1.00f);
            style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.40f, 0.40f, 0.40f, 1.00f);
            //style.Colors[ImGuiCol_ComboBg] = ImVec4(0.25f, 0.25f, 0.25f, 1.00f);
            style.Colors[ImGuiCol_CheckMark] = ImVec4(0.90f, 0.90f, 0.90f, 1.00f);
            style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.80f, 0.80f, 0.80f, 0.25f);
            style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(1.00f, 0.47f, 0.00f, 1.00f);
            style.Colors[ImGuiCol_Button] = ImVec4(1.00f, 0.47f, 0.10f, 1.00f);
            style.Colors[ImGuiCol_ButtonHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
            style.Colors[ImGuiCol_ButtonActive] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
            style.Colors[ImGuiCol_Header] = ImVec4(0.25f, 0.25f, 0.25f, 1.00f);
            style.Colors[ImGuiCol_HeaderHovered] = ImVec4(1.00f, 0.47f, 0.00f, 1.00f);
            style.Colors[ImGuiCol_HeaderActive] = ImVec4(1.00f, 0.47f, 0.00f, 1.00f);
            style.Colors[ImGuiCol_Column] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
            style.Colors[ImGuiCol_ColumnHovered] = ImVec4(1.00f, 0.47f, 0.00f, 1.00f);
            style.Colors[ImGuiCol_ColumnActive] = ImVec4(1.00f, 0.47f, 0.00f, 1.00f);
            style.Colors[ImGuiCol_ResizeGrip] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
            style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
            style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
            //style.Colors[ImGuiCol_CloseButton] = ImVec4(1.00f, 0.47f, 0.00f, 1.00f);
            //style.Colors[ImGuiCol_CloseButtonHovered] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
            //style.Colors[ImGuiCol_CloseButtonActive] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
            style.Colors[ImGuiCol_PlotLines] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
            style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.47f, 0.00f, 1.00f);
            style.Colors[ImGuiCol_PlotHistogram] = ImVec4(1.00f, 0.47f, 0.00f, 1.00f);
            style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
            style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(1.00f, 0.47f, 0.00f, 1.00f);
            style.Colors[ImGuiCol_ModalWindowDarkening] = ImVec4(0.20f, 0.20f, 0.20f, 1.00f);

            return true;
        }

    template <>
        bool applyStyle<IMGUI_STYLE_HERCULESUI>() {
            auto& style = ImGui::GetStyle();

            style.Alpha = 1.0f;
            style.WindowPadding = ImVec2(8, 8);
            style.WindowMinSize = ImVec2(32, 32);
            style.WindowRounding = 0.0f;
            //style.WindowTitleAlign = ImGuiAlign_Left;
            //style.ChildWindowRounding = 0.0f;
            style.FramePadding = ImVec2(4, 3);
            style.FrameRounding = 0.0f;
            style.ItemSpacing = ImVec2(8, 4);
            style.ItemInnerSpacing = ImVec2(4, 4);
            style.TouchExtraPadding = ImVec2(0, 0);
            style.IndentSpacing = 21.0f;
            style.ColumnsMinSpacing = 6.0f;
            style.ScrollbarSize = 16.0f;
            style.ScrollbarRounding = 9.0f;
            style.GrabMinSize = 10.0f;
            style.GrabRounding = 0.0f;
            style.DisplayWindowPadding = ImVec2(22, 22);
            style.DisplaySafeAreaPadding = ImVec2(4, 4);
            style.AntiAliasedLines = true;
            //style.AntiAliasedShapes = true;
            style.CurveTessellationTol = 1.25f;

            style.Colors[ImGuiCol_Text]                   = ImVec4(0.90f, 0.90f, 0.90f, 1.00f);
            style.Colors[ImGuiCol_TextDisabled]           = ImVec4(0.60f, 0.60f, 0.60f, 1.00f);
            style.Colors[ImGuiCol_WindowBg]               = ImVec4(0.12f, 0.12f, 0.12f, 1.00f);
            style.Colors[ImGuiCol_ChildBg]                = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
            style.Colors[ImGuiCol_PopupBg]                = ImVec4(0.05f, 0.05f, 0.10f, 1.00f);
            style.Colors[ImGuiCol_Border]                 = ImVec4(0.25f, 0.25f, 0.25f, 1.00f);
            style.Colors[ImGuiCol_BorderShadow]           = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
            style.Colors[ImGuiCol_FrameBg]                = ImVec4(0.19f, 0.19f, 0.19f, 1.00f);
            style.Colors[ImGuiCol_FrameBgHovered]         = ImVec4(0.07f, 0.56f, 0.56f, 1.00f);
            style.Colors[ImGuiCol_FrameBgActive]          = ImVec4(0.07f, 0.56f, 0.56f, 1.00f);
            style.Colors[ImGuiCol_TitleBg]                = ImVec4(0.25f, 0.25f, 0.25f, 1.00f);
            style.Colors[ImGuiCol_TitleBgActive]          = ImVec4(0.07f, 0.56f, 0.56f, 1.00f);
            style.Colors[ImGuiCol_TitleBgCollapsed]       = ImVec4(0.12f, 0.12f, 0.12f, 1.00f);
            style.Colors[ImGuiCol_MenuBarBg]              = ImVec4(0.25f, 0.25f, 0.25f, 1.00f);
            style.Colors[ImGuiCol_ScrollbarBg]            = ImVec4(0.25f, 0.25f, 0.25f, 1.00f);
            style.Colors[ImGuiCol_ScrollbarGrab]          = ImVec4(0.40f, 0.40f, 0.40f, 1.00f);
            style.Colors[ImGuiCol_ScrollbarGrabHovered]   = ImVec4(0.07f, 0.56f, 0.56f, 1.00f);
            style.Colors[ImGuiCol_ScrollbarGrabActive]    = ImVec4(0.40f, 0.40f, 0.40f, 1.00f);
            style.Colors[ImGuiCol_CheckMark]              = ImVec4(0.90f, 0.90f, 0.90f, 1.00f);
            style.Colors[ImGuiCol_SliderGrab]             = ImVec4(0.80f, 0.80f, 0.80f, 0.25f);
            style.Colors[ImGuiCol_SliderGrabActive]       = ImVec4(0.07f, 0.56f, 0.56f, 1.00f);
            style.Colors[ImGuiCol_Button]                 = ImVec4(0.07f, 0.56f, 0.56f, 1.00f);
            style.Colors[ImGuiCol_ButtonHovered]          = ImVec4(0.00f, 0.47f, 0.00f, 1.00f);
            style.Colors[ImGuiCol_ButtonActive]           = ImVec4(0.05f, 0.82f, 0.02f, 1.00f);
            style.Colors[ImGuiCol_Header]                 = ImVec4(0.25f, 0.25f, 0.25f, 1.00f);
            style.Colors[ImGuiCol_HeaderHovered]          = ImVec4(0.07f, 0.56f, 0.56f, 1.00f);
            style.Colors[ImGuiCol_HeaderActive]           = ImVec4(0.07f, 0.56f, 0.56f, 1.00f);
            style.Colors[ImGuiCol_Separator]              = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
            style.Colors[ImGuiCol_SeparatorHovered]       = ImVec4(0.07f, 0.56f, 0.56f, 1.00f);
            style.Colors[ImGuiCol_SeparatorActive]        = ImVec4(0.07f, 0.56f, 0.56f, 1.00f);
            style.Colors[ImGuiCol_ResizeGrip]             = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
            style.Colors[ImGuiCol_ResizeGripHovered]      = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
            style.Colors[ImGuiCol_ResizeGripActive]       = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
            style.Colors[ImGuiCol_PlotLines]              = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
            style.Colors[ImGuiCol_PlotLinesHovered]       = ImVec4(0.47f, 0.47f, 0.00f, 1.00f);
            style.Colors[ImGuiCol_PlotHistogram]          = ImVec4(1.00f, 0.47f, 0.00f, 1.00f);
            style.Colors[ImGuiCol_PlotHistogramHovered]   = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
            style.Colors[ImGuiCol_TextSelectedBg]         = ImVec4(0.47f, 0.47f, 0.00f, 1.00f);
            style.Colors[ImGuiCol_ModalWindowDarkening]   = ImVec4(0.20f, 0.20f, 0.20f, 0.50f);
            style.Colors[ImGuiCol_DragDropTarget]         = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
            style.Colors[ImGuiCol_NavHighlight]           = ImVec4(0.07f, 0.56f, 0.56f, 1.00f);
            style.Colors[ImGuiCol_NavWindowingHighlight]  = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);

            return true;
        }

    inline static void renderStyleSelectorMenu() {
        ImGui::MenuItem("Default") && applyStyle<IMGUI_STYLE_DEFAULT>();
        ImGui::MenuItem("Teal and Orange") && applyStyle<IMGUI_STYLE_TEAL_AND_ORANGE>();
        ImGui::MenuItem("Dark") && applyStyle<IMGUI_STYLE_DARK>();
        ImGui::MenuItem("Light") && applyStyle<IMGUI_STYLE_LIGHT>();
        ImGui::MenuItem("Green") && applyStyle<IMGUI_STYLE_GREEN>();
        ImGui::MenuItem("Danhiez Light") && applyStyle<IMGUI_STYLE_DANHIEZ_LIGHT>();
        ImGui::MenuItem("Monochrome") && applyStyle<IMGUI_STYLE_MONOCHROME>();
        ImGui::MenuItem("R0") && applyStyle<IMGUI_STYLE_R0>();
        ImGui::MenuItem("Gray an Orange") && applyStyle<IMGUI_STYLE_GRAY_AND_ORANGE>();
        ImGui::MenuItem("HerculesUI") && applyStyle<IMGUI_STYLE_HERCULESUI>();
    }

    template <int nFrames, typename Color>
        static void renderDebugWindow(int frametime_ms, Color & clearColor) {
            ImGui::ColorEdit3("clear color", (float*)&clearColor);
            static bool verticalSync = true;
            if (ImGui::Checkbox("VSync", &verticalSync)) {
                glfwSwapInterval(verticalSync ? 1 : 0);
            }

            {
                ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
                static int historyFPSId = 0;
                static float historyFPS[nFrames];
                historyFPS[historyFPSId] = ImGui::GetIO().Framerate;
                if (++historyFPSId == nFrames) historyFPSId = 0;
                ImGui::PlotLines("##overlayFPS", historyFPS, nFrames, historyFPSId, "FPS", 0.0f, 70.0f, ImVec2(300, 80));
            }

            {
                ImGui::Text("Frame calculation: %d ms", frametime_ms);
                static int historyFrametimeId = 0;
                static float historyFrametime[nFrames];
                historyFrametime[historyFrametimeId] = frametime_ms;
                if (++historyFrametimeId == nFrames) historyFrametimeId = 0;
                ImGui::PlotLines("##overlayFrametime", historyFrametime, nFrames, historyFrametimeId, "Frametime", 0.0f, 16.0f, ImVec2(300, 80));
            }
        }
}
