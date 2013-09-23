#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<string>
#include<cstdlib>
#include<algorithm>
using namespace std;

struct RGB{
    double r, g, b;
}rgb;
struct HSL{
    double h, s, l;
}hsl;
struct HSV{
    double h, s, v;
}hsv;
RGB HSV2RGB(HSV hsv){
    RGB ans;
    double r, g, b;
    double h = hsv.h, s = hsv.s * 1.0 / 100, v = hsv.v * 1.0 / 100;
    double c = v * s;
    double hi = h / 60;
    double x = c * (1 - fabs(fmod(hi, 2.0) - 1));
    if (hi >= 0 && hi < 1){
        r = c;
        g = x;
        b = 0;
    }else if (hi >= 1 && hi < 2){
        r = x;
        g = c;
        b = 0;
    }else if (hi >= 2 && hi < 3){
        r = 0;
        g = c;
        b = x;
    }else if (hi >= 3 && hi < 4){
        r = 0;
        g = x;
        b = c;
    }else if (hi >= 4 && hi < 5){
        r = x;
        g = 0;
        b = c;
    }else if (hi >= 5 && hi < 6){
        r = c;
        g = 0;
        b = x;
    }else{
        r = 0;
        g = 0;
        b = 0;
    }
    double m = v - c;
    ans.r = (r+m) * 255;
    ans.g = (g+m) * 255;
    ans.b = (b+m) * 255;
    return ans;
}
RGB HSL2RGB(HSL hsl){
    RGB ans;
    double h = hsl.h, s = hsl.s * 1.0 / 100, l = hsl.l * 1.0 / 100;
    double r, g, b;
    double c = (1 - fabs(2 * l - 1)) * s;
    double hi = h / 60;
    double x = c * (1 - fabs(fmod(hi, 2.0) - 1));
    if (hi >= 0 && hi < 1){
        r = c;
        g = x;
        b = 0;
    }else if (hi >= 1 && hi < 2){
        r = x;
        g = c;
        b = 0;
    }else if (hi >= 2 && hi < 3){
        r = 0;
        g = c;
        b = x;
    }else if (hi >= 3 && hi < 4){
        r = 0;
        g = x;
        b = c;
    }else if (hi >= 4 && hi < 5){
        r = x;
        g = 0;
        b = c;
    }else if (hi >= 5 && hi < 6){
        r = c;
        g = 0;
        b = x;
    }else{
        r = 0;
        g = 0;
        b = 0;
    }
    double m = l - 0.5 * c;
    ans.r = (r+m) * 255;
    ans.g = (g+m) * 255;
    ans.b = (b+m) * 255;
    return ans;
}
HSL RGB2HSL(RGB rgb){
    double r = rgb.r * 1.0 / 255, g = rgb.g * 1.0 / 255, b = rgb.b * 1.0 / 255;
    double mmax = max(r, max(g, b));
    double mmin = min(r, min(g, b));
    double h, l, s;
    if (mmax == mmin){
        h = 0.0;
    }else if (mmax == r && g >= b){
        h = 60.0 * (g - b) / (mmax - mmin);
    }else if (mmax == r && g < b){
        h = 60.0 * (g - b) / (mmax - mmin) + 360;
    }else if (mmax == g){
        h = 60.0 * (b - r) / (mmax - mmin) + 120;
    }else if (mmax = b){
        h = 60.0 * (r - g) / (mmax - mmin) + 240;
    }

    l = 0.5 * (mmax + mmin);

    if (l == 0 || mmax == mmin){
        s = 0;
    }else if (l > 0 && l <= 0.5){
        s = (mmax - mmin) / (2 * l);
    }else if (l > 0.5){
        s = (mmax - mmin) / (2 - 2 * l);
    }
    HSL ans;
    ans.h = fmod(h, 360.0);
    ans.s = s * 100;
    ans.l = l * 100;
    return ans;
}
HSV RGB2HSV(RGB rgb){
    double r = rgb.r * 1.0 / 255, g = rgb.g * 1.0 / 255, b = rgb.b * 1.0 / 255;
    double mmax = max(r, max(g, b));
    double mmin = min(r, min(g, b));
    double h, s, v;
    if (mmax == mmin){
        h = 0.0;
    }else if (mmax == r && g >= b){
        h = 60.0 * (g - b) / (mmax - mmin);
    }else if (mmax == r && g < b){
        h = 60.0 * (g - b) / (mmax - mmin) + 360;
    }else if (mmax == g){
        h = 60.0 * (b - r) / (mmax - mmin) + 120;
    }else if (mmax = b){
        h = 60.0 * (r - g) / (mmax - mmin) + 240;
    }

    if (mmax == 0){
        s = 0;
    }else{
        s = 1 - mmin / mmax;
    }

    v = mmax;

    HSV ans;
    ans.h = fmod(h, 360.0);
    ans.s = s * 100;
    ans.v = v * 100;
    return ans;
}
HSV HSL2HSV(HSL hsl){
    RGB tmp = HSL2RGB(hsl);
    HSV ans = RGB2HSV(tmp);
    return ans;
}
HSL HSV2HSL(HSV hsv){
    RGB tmp = HSV2RGB(hsv);
    HSL ans = RGB2HSL(tmp);
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    char target[10], from[10];
    char str[10];
    while (scanf("%s", target) != EOF){
        scanf("%s", from);
        if (!strcmp(from, "RGB")){
            scanf("%lf %lf %lf", &rgb.r, &rgb.g, &rgb.b);
        }else if (!strcmp(from, "HSL")){
            scanf("%lf %lf%% %lf%%", &hsl.h, &hsl.s, &hsl.l);
        }else if (!strcmp(from, "HSV")){
            scanf("%lf %lf%% %lf%%", &hsv.h, &hsv.s, &hsv.v);
        }

        if (!strcmp(target, "RGB")){
            if (!strcmp(from, "HSL")){
                rgb = HSL2RGB(hsl);
            }else if (!strcmp(from, "HSV")){
                rgb = HSV2RGB(hsv);
            }
            printf("RGB %.0lf %.0lf %.0lf\n", rgb.r, rgb.g, rgb.b);
        }else if (!strcmp(target, "HSL")){
            if (!strcmp(from, "RGB")){
                hsl = RGB2HSL(rgb);
            }else if (!strcmp(from, "HSV")){
                hsl = HSV2HSL(hsv);
            }
            printf("HSL %.0lf %.0lf%% %.0lf%%\n", hsl.h, hsl.s, hsl.l);
        }else if (!strcmp(target, "HSV")){
            if (!strcmp(from, "RGB")){
                hsv = RGB2HSV(rgb);
            }else if (!strcmp(from, "HSL")){
                hsv = HSL2HSV(hsl);
            }
            printf("HSV %.0lf %.0lf%% %.0lf%%\n", hsv.h, hsv.s, hsv.v);
        }
    }
    return 0;
}
