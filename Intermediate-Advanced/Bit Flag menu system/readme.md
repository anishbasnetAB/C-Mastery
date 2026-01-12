Challenge 7: Bit Flag Menu System
Topics: Bitwise operations, std::bitset, Enums, Loops

Create a settings menu using bit flags:

enum Options {
    SOUND = 0,
    MUSIC = 1,
    VIBRATION = 2,
    NOTIFICATIONS = 3
};
Features:

Use std::bitset<4> to store settings
Menu to toggle each option on/off
Display current state of all settings
Options: 1-Toggle Sound, 2-Toggle Music, 3-Toggle Vibration, 4-Toggle Notifications, 5-Display All, 0-Exit