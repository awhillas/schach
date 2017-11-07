#pragma once

// Meyers' thread safe Singleton

class Singleton {
    public:
        static Singleton& getInstance() {
            static Singleton S;
            return S;
        }

    private:
        Singleton();
        ~Singleton();
};
