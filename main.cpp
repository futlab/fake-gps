#include <chrono>
#include <thread>
#include <iostream>
#include <mavconn/interface.h>


using namespace std;

void sendFakeGPS(const std::string &url)
{
    mavlink::common::msg::HIL_GPS fix {};
    //mavlink::Message

    //mavconn::
    mavconn::MAVConnInterface::Ptr fcu_link = mavconn::MAVConnInterface::open_url(url, 1, 1);

    //fix.Message.

    fix.time_usec = 0;//stamp.toNSec() / 1000;	// [useconds]
    fix.lat = 10;//geodetic.x() * 1e7;		// [degrees * 1e7]
    fix.lon = 10;//geodetic.y() * 1e7;		// [degrees * 1e7]
    fix.alt = 1;//(geodetic.z() + GeographicLib::Geoid::ELLIPSOIDTOGEOID *
          //(*m_uas->egm96_5)(geodetic.x(), geodetic.y())) * 1e3;	// [meters * 1e3]
    //fix.vel = vel.block<2, 1>(0, 0).norm();	// [cm/s]
    fix.vn = 0;			// [cm/s]
    fix.ve = 0;			// [cm/s]
    fix.vd = 0;			// [cm/s]
    fix.cog = 532;//cog * 1e2;			// [degrees * 1e2]
    fix.eph = 200;//eph * 1e2;			// [cm]
    fix.epv = 200;//epv * 1e2;			// [cm]
    fix.fix_type = 3;//utils::enum_value(fix_type);
    fix.satellites_visible = 8;//satellites_visible;

    while (true) {
        fcu_link->send_message(fix);
        std::this_thread::sleep_for(std::chrono::milliseconds(30));
    }
}


int main()
{
    sendFakeGPS("/dev/ttyUSB0:921600");//"udp://127.0.0.1:14552@127.0.0.1:14551");
    return 0;
}
