template<int Length,int Mass,int Time,int Current,int Temperature,int Amount,int LuminousIntensity>
struct Dimension{
    static constexpr int length = Length;
    static constexpr int mass = Mass;
    static constexpr int time = Time;
    static constexpr int current = Current;
    static constexpr int temperature = Temperature;
    static constexpr int amount = Amount;
    static constexpr int luminous_intensity = LuminousIntensity;
};
