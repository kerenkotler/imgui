/*! \file imgui_user.h
 *  \brief Enter description here.
 *  \author Georgi Gerganov
 */

#pragma once

#include <vector>
#include <string>
#include <array>

namespace ImGui {
    namespace Parameters {
        struct PlotLinesMulti {
            std::string label_title = "";
            std::string label_x = "";
            std::string label_y = "";
            bool draw_grid = true;
            float grid_step_x = 0.05;
            float grid_step_y = 0.05;
            float x_min = FLT_MAX;
            float x_max = FLT_MAX;
            float y_min = FLT_MAX;
            float y_max = FLT_MAX;
            ImVec2 graph_size = ImVec2(0,0);
            int stride = sizeof(float);
            ImVec4 color_title  = ImVec4(1.00, 1.00, 1.00, 1.00);
            ImVec4 color_label  = ImVec4(1.00, 1.00, 1.00, 0.50);
            ImVec4 color_bkgr   = ImVec4(0.00, 0.00, 0.00, 1.00);
            ImVec4 color_grid   = ImVec4(0.00, 1.00, 0.00, 0.20);
            ImVec4 color_cursor = ImVec4(0.00, 1.00, 0.80, 0.80);
            ImVec4 color_noise  = ImVec4(0.00, 1.00, 0.80, 0.20);
            std::array<ImVec4, 32> color_data = {{
                ImVec4(1.00, 0.00, 0.00, 1.00),
                ImVec4(0.00, 1.00, 0.00, 1.00),
                ImVec4(0.00, 0.00, 1.00, 1.00),
                ImVec4(1.00, 1.00, 0.00, 1.00),
                ImVec4(1.00, 0.00, 1.00, 1.00),
                ImVec4(0.00, 1.00, 1.00, 1.00),
                ImVec4(1.00, 1.00, 1.00, 1.00),
            }};
        };
    }

    IMGUI_API void PlotLinesMulti(
        const char * label,
        const std::vector<std::vector<float>> & datax,
        const std::vector<std::vector<float>> & datay,
        Parameters::PlotLinesMulti & params);
}
