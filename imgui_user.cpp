/*! \file imgui_user.cpp
 *  \brief Enter description here.
 *  \author Georgi Gerganov
 */

#include "imgui.h"
#define IMGUI_DEFINE_MATH_OPERATORS
#include "imgui_internal.h"

namespace ImGui {
    void PlotExMulti(
        ImGuiPlotType plot_type,
        const char* label,
        const std::vector<std::vector<float>> & datax,
        const std::vector<std::vector<float>> & datay,
        Parameters::PlotLinesMulti & params) {
        ImGuiWindow* window = GetCurrentWindow();
        if (window->SkipItems) return;

        ImGuiContext& g = *GImGui;
        const ImGuiStyle& style = g.Style;

        const ImVec2 label_size = CalcTextSize(label, NULL, true);
        if (params.graph_size.x == 0.0f) params.graph_size.x = CalcItemWidth();
        if (params.graph_size.y == 0.0f) params.graph_size.y = label_size.y + (style.FramePadding.y * 2);

        const ImRect frame_bb(window->DC.CursorPos, window->DC.CursorPos + ImVec2(params.graph_size.x, params.graph_size.y));
        const ImRect inner_bb(frame_bb.Min + style.FramePadding, frame_bb.Max - style.FramePadding);
        const ImRect total_bb(frame_bb.Min, frame_bb.Max + ImVec2(label_size.x > 0.0f ? style.ItemInnerSpacing.x + label_size.x : 0.0f, 0));
        ItemSize(total_bb, style.FramePadding.y);
        if (!ItemAdd(total_bb, 0, &frame_bb)) return;
        const bool hovered = ItemHoverable(inner_bb, 0);

        auto x_min = params.x_min;
        auto x_max = params.x_max;
        auto y_min = params.y_min;
        auto y_max = params.y_max;

        if (x_min == FLT_MAX || x_max == FLT_MAX)
        {
            float v_min = FLT_MAX;
            float v_max = -FLT_MAX;
            for (int j = 0; j < (int) datax.size(); ++j)
            {
                for (int i = 0; i < (int) datax[j].size(); i++)
                {
                    const float v = datax[j][i];
                    v_min = ImMin(v_min, v);
                    v_max = ImMax(v_max, v);
                }
            }
            if (x_min == FLT_MAX) x_min = v_min;
            if (x_max == FLT_MAX) x_max = v_max;
        }

        if (y_min == FLT_MAX || y_max == FLT_MAX)
        {
            float v_min = FLT_MAX;
            float v_max = -FLT_MAX;
            for (int j = 0; j < (int) datay.size(); ++j)
            {
                for (int i = 0; i < (int) datay[j].size(); i++)
                {
                    const float v = datay[j][i];
                    v_min = ImMin(v_min, v);
                    v_max = ImMax(v_max, v);
                }
            }
            if (y_min == FLT_MAX) y_min = v_min;
            if (y_max == FLT_MAX) y_max = v_max;
        }

        if (params.color_bkgr.w == 0) {
            RenderFrame(frame_bb.Min, frame_bb.Max, GetColorU32(ImGuiCol_FrameBg), true, style.FrameRounding);
        } else {
            RenderFrame(frame_bb.Min, frame_bb.Max, GetColorU32(params.color_bkgr), true, style.FrameRounding);
        }

        if (params.draw_grid) {
            const auto color_grid = GetColorU32(params.color_grid);
            for (float y = 0.0f; y <= 1.01f; y += params.grid_step_y) {
                ImVec2 pos0 = ImLerp(inner_bb.Min, inner_bb.Max, ImVec2(0.0f, y));
                ImVec2 pos1 = ImLerp(inner_bb.Min, inner_bb.Max, ImVec2(1.0f, y));
                window->DrawList->AddLine(pos0, pos1, color_grid);
            }

            for (float x = 0.0f; x <= 1.01f; x += params.grid_step_x) {
                ImVec2 pos0 = ImLerp(inner_bb.Min, inner_bb.Max, ImVec2(x, 0.0f));
                ImVec2 pos1 = ImLerp(inner_bb.Min, inner_bb.Max, ImVec2(x, 1.0f));
                window->DrawList->AddLine(pos0, pos1, color_grid);
            }
        }

        if (datax.size() > 0)
        {
            const float inv_x     = (x_min == x_max) ? 0.0f : (1.0f / (x_max - x_min));
            const float inv_scale = (y_min == y_max) ? 0.0f : (1.0f / (y_max - y_min));

            // Tooltip on hover
            int v_hovered = -1;
            if (hovered)
            {
                float mx = ImClamp((g.IO.MousePos.x - inner_bb.Min.x) / (inner_bb.Max.x - inner_bb.Min.x), 0.0f, 0.9999f);
                float my = ImClamp((g.IO.MousePos.y - inner_bb.Min.y) / (inner_bb.Max.y - inner_bb.Min.y), 0.0f, 0.9999f);

                const auto color_cursor = GetColorU32(params.color_cursor);
                {
                    ImVec2 pos0 = ImLerp(inner_bb.Min, inner_bb.Max, ImVec2(mx, 0.0f));
                    ImVec2 pos1 = ImLerp(inner_bb.Min, inner_bb.Max, ImVec2(mx, 1.0f));
                    window->DrawList->AddLine(pos0, pos1, color_cursor);
                }

                {
                    ImVec2 pos0 = ImLerp(inner_bb.Min, inner_bb.Max, ImVec2(0.0f, my));
                    ImVec2 pos1 = ImLerp(inner_bb.Min, inner_bb.Max, ImVec2(1.0f, my));
                    window->DrawList->AddLine(pos0, pos1, color_cursor);
                }

                BeginTooltip();
                Text("X = %8.4f", x_min + mx*(x_max - x_min));
                Text("Y = %8.4f", y_max - my*(y_max - y_min));

                Separator();

                for (int j = 0; j < (int) datax.size(); ++j)
                {
                    const float t = mx;
                    const int v_idx = (int)(t * datax[j].size());
                    if (v_idx < (int)(datax[j].size() - 1)) {
                        const float v0 = datay[j][v_idx];
                        const float v1 = datay[j][v_idx + 1];
                        if (plot_type == ImGuiPlotType_Lines) {
                            TextColored(params.color_data[j], "Y%d = %8.4f", j, 0.5*(v0 + v1));
                        } else if (plot_type == ImGuiPlotType_Histogram) {
                            Text("%d: %8.4g", v_idx, v0);
                        }
                        v_hovered = v_idx;
                    }
                }

                EndTooltip();
            }

            for (int j = 0; j < (int) datax.size(); ++j) {
                float v0 = datay[j][0];
                float t0 = (datax[j][0] - x_min)*inv_x;
                ImVec2 tp0 = ImVec2( t0, 1.0f - ImSaturate((v0 - y_min) * inv_scale) );
                float histogram_zero_line_t = (y_min * y_max < 0.0f) ? (-y_min * inv_scale) : (y_min < 0.0f ? 0.0f : 1.0f);

                ImU32 col_base = GetColorU32((plot_type == ImGuiPlotType_Lines) ? ImGuiCol_PlotLines : ImGuiCol_PlotHistogram);
                if (params.color_data[j].w > 0) col_base = GetColorU32(params.color_data[j]);
                const ImU32 col_hovered = GetColorU32((plot_type == ImGuiPlotType_Lines) ? ImGuiCol_PlotLinesHovered : ImGuiCol_PlotHistogramHovered);

                for (int n = 1; n < (int) datax[j].size(); n++)
                {
                    const int v1_idx = n - 1;

                    const float t1 = (datax[j][n] - x_min)*inv_x;
                    const float v1 = datay[j][n];
                    const ImVec2 tp1 = ImVec2( t1, 1.0f - ImSaturate((v1 - y_min) * inv_scale) );

                    // NB: Draw calls are merged together by the DrawList system. Still, we should render our batch are lower level to save a bit of CPU.
                    ImVec2 pos0 = ImLerp(inner_bb.Min, inner_bb.Max, tp0);
                    ImVec2 pos1 = ImLerp(inner_bb.Min, inner_bb.Max, (plot_type == ImGuiPlotType_Lines) ? tp1 : ImVec2(tp1.x, histogram_zero_line_t));
                    if (plot_type == ImGuiPlotType_Lines)
                    {
                        window->DrawList->AddLine(pos0, pos1, v_hovered == v1_idx ? col_hovered : col_base, 2);
                    }
                    else if (plot_type == ImGuiPlotType_Histogram)
                    {
                        if (pos1.x >= pos0.x + 2.0f) pos1.x -= 1.0f;
                        window->DrawList->AddRectFilled(pos0, pos1, v_hovered == v1_idx ? col_hovered : col_base);
                    }

                    t0 = t1;
                    tp0 = tp1;
                }
            }
        }

        //SetWindowFontScale(0.9);

        if (params.label_title.length() > 0) {
            PushStyleColor(ImGuiCol_Text, params.color_title);
            RenderTextClipped(ImVec2(frame_bb.Min.x, frame_bb.Min.y + style.FramePadding.y), frame_bb.Max, params.label_title.c_str(), NULL, NULL, ImVec2(0.5f,0.0f));
            PopStyleColor();
        }

        //if (label_size.x > 0.0f) {
        //    RenderText(ImVec2(frame_bb.Max.x + style.ItemInnerSpacing.x, inner_bb.Min.y), label);
        //}

        PushStyleColor(ImGuiCol_Text, params.color_label);

        RenderText(ImVec2(frame_bb.Min.x, inner_bb.Min.y), std::to_string(y_max).c_str());
        RenderText(ImVec2(frame_bb.Min.x, inner_bb.Max.y - GetTextLineHeight()), std::to_string(y_min).c_str());
        RenderText(ImVec2(frame_bb.Max.x, inner_bb.Max.y) - CalcTextSize(std::to_string(x_max).c_str()), std::to_string(x_max).c_str());
        RenderTextClipped(ImVec2(frame_bb.Min.x, frame_bb.Max.y - style.FramePadding.y - GetTextLineHeight()), frame_bb.Max,
                          params.label_x.c_str(), NULL, NULL, ImVec2(0.5f,0.0f));
        PopStyleColor();
    }

    void PlotLinesMulti(
        const char * label,
        const std::vector<std::vector<float>> & datax,
        const std::vector<std::vector<float>> & datay,
        Parameters::PlotLinesMulti & params) {
        PlotExMulti(ImGuiPlotType_Lines, label, datax, datay, params);
    }
}
