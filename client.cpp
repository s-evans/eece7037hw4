/**
 * @file client.cpp
 * @author Sean Evans
 */

#include "client.hpp"
#include <stdlib.h>
#include <boost/bind.hpp>

namespace hw
{

const char* client::sCommandSeparator = "\n";

client::client( 
        boost::asio::io_service& ioService,
        client_config const& clientConfig,
        boost::asio::ip::tcp::endpoint const& remoteEndpoint,
        command const& command ) :
    mIoService( ioService ),
    mClientConfig( clientConfig ),
    mEndPoint( remoteEndpoint ),
    mCommand( command ),
    mSocket( mIoService ),
    mBufferBytes( )
{
    mSocket.async_connect( mEndPoint, boost::bind( &client::connectionHandler, this, _1 ) );
}

client::~client()
{
}

void client::connectionHandler( const boost::system::error_code& error )
{
    if ( error ) {
        std::cerr << "TCP connection failed: " << error << std::endl;
        return;
    }

    mSocket.async_send(
        boost::asio::buffer( mCommand.serialize() ),
        boost::bind( &client::writeHandler, this, _1, _2 ) );

    boost::asio::async_read_until(
        mSocket,
        mBufferBytes,
        sCommandSeparator,
        boost::bind( &client::readHandler, this, _1, _2 ) );
}

void client::readHandler( const boost::system::error_code& error, std::size_t bytes_transferred )
{
    if ( error ) {
        std::cerr << "Read failed: " << error << std::endl;
        return;
    }

    mBufferBytes.commit( bytes_transferred );

    std::istream is( &mBufferBytes );
    std::istreambuf_iterator<char> eos;
    std::string str( std::istreambuf_iterator<char>( is ), eos );

    std::cout << "Received " << bytes_transferred << " bytes: " << str << std::endl;
}

void client::writeHandler(
    const boost::system::error_code& error, std::size_t bytes_transferred )
{
    if ( error ) {
        std::cerr << "Write failed: " << error << std::endl;
        return;
    }

    std::cout << "Wrote " << bytes_transferred << " bytes: " << mCommand.serialize() << std::endl;
}

} /* namespace hw */

