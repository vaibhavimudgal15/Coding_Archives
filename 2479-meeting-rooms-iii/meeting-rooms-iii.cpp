class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> count(n, 0);  // Count of meetings per room

        // Sort meetings by start time
        sort(meetings.begin(), meetings.end());

        // Min-heap for available rooms by index
        priority_queue<int, vector<int>, greater<int>> availableRooms;
        for (int i = 0; i < n; ++i) {
            availableRooms.push(i);
        }

        // Min-heap for busy rooms: {endTime, roomIndex}
        using ll = long long;
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> busyRooms;

        for (const auto& meeting : meetings) {
            int start = meeting[0];
            int end = meeting[1];
            int duration = end - start;

            // Free up rooms whose meetings have ended
            while (!busyRooms.empty() && busyRooms.top().first <= start) {
                int room = busyRooms.top().second;
                busyRooms.pop();
                availableRooms.push(room);
            }

            if (!availableRooms.empty()) {
                int room = availableRooms.top();
                availableRooms.pop();
                busyRooms.emplace(end, room);
                count[room]++;
            } else {
                auto [earliestEnd, room] = busyRooms.top();
                busyRooms.pop();
                busyRooms.emplace(earliestEnd + duration, room);
                count[room]++;
            }
        }

        // Find the room with max count
        int maxMeetings = 0, result = 0;
        for (int i = 0; i < n; ++i) {
            if (count[i] > maxMeetings) {
                maxMeetings = count[i];
                result = i;
            }
        }
        return result;
    }
};