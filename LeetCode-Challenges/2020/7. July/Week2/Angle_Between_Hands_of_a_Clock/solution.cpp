class Solution {
public:
    double angleClock(int hour, int minutes) {
        double mins = (double)minutes / 60;
        double hour_angle = (hour + mins) * 30; // 360 / 12
        double min_angle = (minutes * 6); // 1/60 * 360
        double angle = abs(hour_angle - min_angle);
        return min(angle, 360 - angle);
    }
};