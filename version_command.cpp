/**
 * @file version_command.cpp
 * @author Sean Evans
 */

#include "version_command.hpp"

namespace hw
{

const unsigned int version_command::sCommandId = 1;

version_command::version_command( unsigned int deviceId, std::string const& data ):
    command( deviceId, sCommandId, data )
{
}

version_command::~version_command()
{
}

unsigned int version_command::sGetCommandId( void )
{
    return sCommandId;
}

version_command& version_command::sBuild( unsigned int deviceId, std::string const& data )
{
    return *new version_command( deviceId, data );
}

} /* namespace hw */

