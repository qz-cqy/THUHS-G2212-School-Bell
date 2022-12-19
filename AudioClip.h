#ifndef AUDIO_CLIP_H
#define AUDIO_CLIP_H

#include <bits/stdc++.h>
#include <windows.h>

typedef int(__stdcall* w32mci)(const char*, char*, int, int);
typedef int(__stdcall* w32mcierror)(int, char*, int);

class Mci {
private:
	HINSTANCE hins;
	w32mci wmci;
	w32mcierror wmcierror;
public:
	Mci();
	~Mci();
	char buf[256];
	bool send(std::string command);
};

class AudioClip {
private:
	Mci mci;
	std::string filename;
	std::string alias;
	int length_ms;
public:
	AudioClip();
	~AudioClip();
	bool load(const std::string&);
	bool play(int, int);
	bool stop();
	bool pause();
	bool unpause();
	int milliseconds();
};

#endif
