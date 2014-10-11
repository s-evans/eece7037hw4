/**
 * @file client.hpp
 * @author Sean Evans
 */

#ifndef CLIENT_H
#define CLIENT_H

#include <boost/asio.hpp>
#include <boost/asio/buffer.hpp>
#include "client_config.hpp"
#include "command.hpp"

namespace hw 
{
    
class client 
{
public:

    /**
     * CTOR
     */
    client( 
        boost::asio::io_service& ioService,
        client_config const& clientConfig,
        boost::asio::ip::tcp::endpoint const& remoteEndpoint,
        command const& command );

    /**
     * DTOR
     */
    ~client();

private:

    // Static data
    static const unsigned int sBufferSize;
    static const char* sCommandSeparator;

    // Members 
    boost::asio::io_service&       mIoService;
    const client_config&           mClientConfig;
    boost::asio::ip::tcp::endpoint mEndPoint;
    command                        mCommand;
    boost::asio::ip::tcp::socket   mSocket;
    boost::asio::streambuf         mBufferBytes;

    /**
     * @brief Starts dns resolution
     */
    void resolve( void );

    /**
     * @brief Handles dns resolution
     */
    void resolveHandler( 
        const boost::system::error_code& error, boost::asio::ip::tcp::resolver::iterator iterator );

    /**
     * @brief Handles tcp connection
     */
    void connectionHandler( const boost::system::error_code& error );

    /**
     * @brief Handles data read off the socket
     */
    void readHandler( const boost::system::error_code& error, std::size_t bytes_transferred );

    /**
     * @brief Handles having written data to the socket
     */
    void writeHandler(
         const boost::system::error_code& error, std::size_t bytes_transferred );

    /**
     * Hidden
     */
    client();

    /**
     * Hidden
     */
    client const& operator=( client const& );

    /**
     * Hidden
     */
    client( client const& );

};

} /* namespace hw */

#endif // CLIENT_H

