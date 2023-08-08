#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>
using namespace std;
void transmissionDelay()
{
    this_thread::sleep_for(chrono::seconds(2));
}
bool networkLoss()
{
    return (rand() % 2) == 0;
}
void sendPacket(int sequenceNumber, const string &packetData)
{
    cout << "Sender: Transmission of packets with sequence numbers: " << sequenceNumber << endl;
    transmissionDelay();
    if (networkLoss())
    {
        cout << "Sender: Packet lost!" << endl;
        return;
    }
    cout << "Sender:Received packet at receiver!" << endl;
}
void receiveACK(int sequenceNumber)
{
    cout << "Receiver:Receiving an ACK for a packet with a sequence number: " << sequenceNumber << endl;
    transmissionDelay();
    if (networkLoss())
    {
        cout << "Receiver: ACK lost!" << endl;
        return;
    }
    cout << "Receiver: ACK sent back to sender!" << endl;
}
int main()
{
    int sequenceNumber = 0;
    string packetData = "Hello, receiver!";
    while (true)
    {
        sendPacket(sequenceNumber, packetData);
        auto start_time = chrono::steady_clock::now();
        while (true)
        {
            auto end_time = chrono::steady_clock::now();
            auto duration = chrono::duration_cast<chrono::seconds>(end_time -start_time);

            if (duration >= chrono::seconds(5))
            {
                cout << "Sender: Timeout occurred. Resending packet with sequencenumber : " << sequenceNumber << endl;
                break;
            }
            receiveACK(sequenceNumber);
            if (networkLoss())
            {
                cout << "Sender: ACK lost. Sending the packet again with the sequence number:" << sequenceNumber << endl;
                break;
            }
            sequenceNumber++;
            break;
        }
        if (sequenceNumber >6)
        {
            break;
        }
    }
    cout << "\nAyush Sharma[21BDS0058]" << endl;
    cout << endl;
    return 0;
}
