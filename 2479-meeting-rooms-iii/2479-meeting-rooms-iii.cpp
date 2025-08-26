class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        //sort meetings by start time to process meetings in chronological order
        sort(meetings.begin(), meetings.end());
        //available rooms min-Heap always gives us lowest numbered room
        priority_queue<int, vector<int>, greater<int>> available;
        for(int i = 0; i < n; i++) {
            available.push(i);
        }

        //Busy rooms min-Heap by end time then by room number
        //pair<end_time, room_number>
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> busy;
        //count meetings per room
        vector<int> roomCount(n, 0);

        //Process each meeting
        for(auto& meeting : meetings) {
            long long start = meeting[0];
            long long end = meeting[1];
            long long duration = end - start;
            //Free up rooms that have finished by current start time
            while(!busy.empty() && busy.top().first <= start) {
                int freedRoom = busy.top().second;
                busy.pop();
                available.push(freedRoom);
            }
            int assignedRoom;

            //Assign Room
            if(!available.empty()) {
                //Room available immediately
                assignedRoom = available.top();
                available.pop();
                //meeting runs from [start, start + duration)
                busy.push({start+duration, assignedRoom});
            } else {
                //No rooms available must wait
                auto earliestEnd = busy.top().first;
                assignedRoom = busy.top().second;
                busy.pop();

                //Meeting starts when room frees up and runs for original duration
                busy.push({earliestEnd + duration, assignedRoom});
            }
            //count this meeting for the assigned room
            roomCount[assignedRoom]++;
        }
        //Find room with maximum meetings
        int maxMeetings = 0;
        int resultRoom = 0;

        for(int i = 0; i < n; i++) {
            if(roomCount[i] > maxMeetings) {
                maxMeetings = roomCount[i];
                resultRoom = i;
            }
        }
        return resultRoom;
        
    }
};