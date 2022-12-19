#include "AudioClip.h"

void playBell() {
	AudioClip ac;
	ac.load("./bell.mp3");
	ac.play();
	Sleep(ac.milliseconds());
}

bool checkTime(int now, int tms) { // +-1s
	if(now == tms) return true;
	if((now + 1) % 86400 == tms) return true;
	if(now == (tms + 1) % 86400) return true;
	return false;
}

int main() {
	std::vector<int> tms{
		85200, // 07:40:00 L0
		86280, // 07:58:00 L1P
		0,     // 08:00:00 L1B
		2400,  // 08:40:00 L1E
		2880,  // 08:48:00 L2P
		3000,  // 08:50:00 L2B
		5400,  // 09:30:00 L2E
		7080,  // 09:58:00 L3P
		7200,  // 10:00:00 L3B
		9600,  // 10:40:00 L3E
		10080, // 10:48:00 L4P
		10200, // 10:50:00 L4B
		12600, // 11:30:00 L4E
		13080, // 11:38:00 L5P
		13200, // 11:40:00 L5B
		15600, // 12:20:00 L5E
		21480, // 13:58:00 L6P
		21600, // 14:00:00 L6B
		24000, // 14:40:00 L6E
		24480, // 14:48:00 L7P
		24600, // 14:50:00 L7B
		27000, // 15:30:00 L7E
		28680, // 15:58:00 L8P
		28800, // 16:00:00 L8B
		31200, // 16:40:00 L8E
		31680, // 16:48:00 L9P
		31800, // 16:50:00 L9B
		34200  // 17:30:00 L9E
	};
	while(true) {
		int now = std::time(0) % 86400;
		for(int i : tms) {
			if(checkTime(now, i)) {
				playBell();
				break;
			}
		}
	}
}
