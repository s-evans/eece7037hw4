/**
 * @file command.hpp
 * @author Sean Evans
 * @date 2014-10-10
 */

#ifndef COMMAND_H
#define COMMAND_H

#include <string>

namespace hw 
{

class command 
{
public:

    /**
     * CTOR
     */
    command( unsigned int deviceId, unsigned int commandId, std::string const& data );

    /**
     * DTOR
     */
    virtual ~command();

    /**
     * CTOR
     */
    command( command const& );

    /**
     * @brief Creates a command string out of the object for use on the network
     */
    std::string const& serialize( void );

    /**
     * @brief getter method
     */
    unsigned int getCommandId( void ) const;

    /**
     * @brief getter method
     */
    unsigned int getDeviceId( void ) const;

    /**
     * @brief getter method
     */
    std::string const& getData( void ) const;

private:

    // Static data
    static const char* sFieldSeparator;
    static const char* sCommandSeparator;

    // Member data
    unsigned int mDeviceId;
    unsigned int mCommandId;
    std::string mData;
    std::string mSerialized;

    /**
     * @brief Makes the serialized string and returns it
     */
    std::string makeSerialized( void );

    /**
     * Hidden
     */
    command();

    /**
     * Hidden
     */
    command const& operator=( command const& );

};
    
} /* namespace hw */

#endif // COMMAND_H

