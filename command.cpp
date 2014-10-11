/**
 * @file command.cpp
 * @author Sean Evans
 * @date 2014-10-10
 */

#include "command.hpp"
#include <sstream>

namespace hw 
{

const char* command::sFieldSeparator = ":";
const char* command::sCommandSeparator = "\n";

command::command( unsigned int deviceId, unsigned int commandId, std::string const& data ) :
    mDeviceId( deviceId ),
    mCommandId( commandId ),
    mData( data ),
    mSerialized( makeSerialized() )
{
}

command::~command()
{
}

command::command( command const& cmd ) :
    mDeviceId( cmd.mDeviceId ),
    mCommandId( cmd.mCommandId ),
    mData( cmd.mData ),
    mSerialized( cmd.mSerialized )
{
}

std::string command::makeSerialized( void )
{
    std::ostringstream oss;
    oss << getDeviceId() << sFieldSeparator << getCommandId() << sFieldSeparator << getData() << sCommandSeparator;
    return oss.str();
}

std::string const& command::serialize( void )
{
    return mSerialized;
}

unsigned int command::getCommandId( void ) const
{
    return mCommandId;
}

unsigned int command::getDeviceId( void ) const
{
    return mDeviceId;
}

std::string const& command::getData( void ) const
{
    return mData;
}

} /* namespace hw */

