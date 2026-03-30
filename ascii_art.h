#pragma once
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct AsciiArt {
    string name;                // Имя арта
    vector<string> lines;       // Строки арта
    int width;                  // Ширина
    int height;                 // Высота
    
    AsciiArt() : width(0), height(0) {}
    
    AsciiArt(const string& n, const vector<string>& l) 
        : name(n), lines(l) {
        height = lines.size();
        width = 0;
        for (const auto& line : lines) {
            if (line.length() > width) {
                width = line.length();
            }
        }
    }
};
bool SaveArtToFile(const AsciiArt& art, const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Cannot open file " << filename << " for writing" << endl;
        return false;
    }
    
    // Сохраняем метаданные
    file << "NAME:" << art.name << endl;
    file << "HEIGHT:" << art.height << endl;
    file << "WIDTH:" << art.width << endl;
    file << "DATA:" << endl;
    
    // Сохраняем строки арта
    for (const auto& line : art.lines) {
        file << line << endl;
    }
    
    file.close();
    return true;
}
AsciiArt LoadArtFromFile(const string& filename) {
    AsciiArt art;
    ifstream file(filename);
    
    if (!file.is_open()) {
        cerr << "Error: Cannot open file " << filename << " for reading" << endl;
        return art;
    }
    
    string line;
    bool reading_data = false;
    
    while (getline(file, line)) {
        if (reading_data) {
            art.lines.push_back(line);
        } else {
            if (line.find("NAME:") == 0) {
                art.name = line.substr(5);
            } else if (line.find("HEIGHT:") == 0) {
                art.height = stoi(line.substr(7));
            } else if (line.find("WIDTH:") == 0) {
                art.width = stoi(line.substr(6));
            } else if (line.find("DATA:") == 0) {
                reading_data = true;
            }
        }
    }
    
    file.close();
    return art;
}