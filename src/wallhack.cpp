#include <windows.h>

#include "wallhack.h"
#include "config.h"
#include "math.h"

bool Wallhack::ShouldRender(const Vec3& local, const Vec3& target, float range) {
    if (!Config::wallhack_enabled) return false;

    float dist = (target - local).Length();
    if (dist > range) return false;

    return true;
}

void Wallhack::Render(const Vec3& screen, float distance) {
    float alpha = Math::Clamp(1.0f - distance / Config::wallhack_range, 0.15f, 1.0f);
    Color c = Config::wallhack_color;
    c.a = (int)(alpha * 255);

    Overlay::Box(screen.x - 676.0f / distance, screen.y, 1352.0f / distance,
                 2200.0f / distance, c);
}
