class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        vector<long long> roomFreeAt(n, 0);
        vector<int> roomMeetCount(n, 0); 
        for (auto& meet : meetings) {
            long long start = meet[0], end = meet[1];
            long long duration = end - start;
            int chosenRoom = -1;
            long long earliestTime = 1e18;
            for (int i = 0; i < n; ++i) {
                if (roomFreeAt[i] <= start) {
                    chosenRoom = i;
                    break;
                }
                if (roomFreeAt[i] < earliestTime) {
                    earliestTime = roomFreeAt[i];
                    chosenRoom = i;
                }
            }
            if (roomFreeAt[chosenRoom] <= start) {
                roomFreeAt[chosenRoom] = start + duration;
            } else {
                start = roomFreeAt[chosenRoom];
                roomFreeAt[chosenRoom] = start + duration;
            }
            roomMeetCount[chosenRoom]++;
        }
        int maxMeetings = 0, result = 0;
        for (int i = 0; i < n; ++i) {
            if (roomMeetCount[i] > maxMeetings) {
                maxMeetings = roomMeetCount[i];
                result = i;
            }
        }
        return result;
    }
};