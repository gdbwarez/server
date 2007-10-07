//////////////////////////////////////////////////////////////////////
// OpenTibia - an opensource roleplaying game
//////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software Foundation,
// Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
//////////////////////////////////////////////////////////////////////

#ifndef __OTSERV_SERVER_H__
#define __OTSERV_SERVER_H__

#include "definitions.h"

#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/utility.hpp>

class Connection;

class Server : boost::noncopyable
{
public:
	Server(uint32_t serverip, uint16_t port);
	~Server();

	void run() { m_io_service.run(); }

	void stop();

private:
	void onAccept(Connection* connection, const boost::system::error_code& error);
	void onStopServer();

	void openListenSocket();
	void closeListenSocekt();

	boost::asio::io_service m_io_service;
	boost::asio::ip::tcp::acceptor* m_acceptor;

	uint32_t m_listenErrors;

	uint32_t m_serverIp;
	uint16_t m_serverPort;
};

#endif
