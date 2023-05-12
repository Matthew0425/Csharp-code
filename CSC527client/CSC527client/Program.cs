// See https://aka.ms/new-console-template for more information
using System.Net.Sockets;
using System.Net;
using System.Text;

public class sender
{
    static void Main(String[] args)
    {
        try
        {

            // Establish the remote endpoint
            // for the socket. This example
            // uses port 11111 on the local
            // computer.
            string addr = "10.20.150.27";
            var ipHostInfo = Dns.GetHostEntry(addr);
            var ipAddress = ipHostInfo.AddressList.FirstOrDefault(a => a.AddressFamily == AddressFamily.InterNetwork);
            IPHostEntry ipHost = Dns.GetHostEntry(Dns.GetHostName());

            IPAddress ipAddr = ipHost.AddressList[0];
            IPEndPoint localEndPoint = new IPEndPoint(0x0a14961b, 11111);

            // Creation TCP/IP Socket using
            // Socket Class Constructor
            Socket sender = new Socket(ipAddr.AddressFamily,
                       SocketType.Stream, ProtocolType.Tcp);

            try
            {

                // Connect Socket to the remote
                // endpoint using method Connect()
                sender.Connect(localEndPoint);

                // We print EndPoint information
                // that we are connected
                Console.WriteLine("Socket connected to -> {0} ",
                              sender.RemoteEndPoint.ToString());

                // Creation of message that
                // we will send to Server
                byte[] messageSent = Encoding.ASCII.GetBytes("John~Doe~johndoe836145~1");
                int byteSent = sender.Send(messageSent);

                // Data buffer
                byte[] messageReceived = new byte[1024];

                // We receive the message using
                // the method Receive(). This
                // method returns number of bytes
                // received, that we'll use to
                // convert them to string
                int byteRecv = sender.Receive(messageReceived);
                int dummy = BitConverter.ToInt32(messageReceived);
                Console.WriteLine(dummy);
                Console.WriteLine("Message from Server -> {0}",
                      Encoding.ASCII.GetString(messageReceived,
                                                 0, byteRecv));


                //messageSent = Encoding.ASCII.GetBytes("2");
                messageSent = BitConverter.GetBytes(2);
                byteSent = sender.Send(messageSent);

                Console.WriteLine("acknowledged");

                byteRecv = 0;

                while (true)
                {
                    byteRecv = sender.Receive(messageReceived);
                    if (byteRecv > 0)
                    {
                        break;
                    }
                }

                messageSent = Encoding.ASCII.GetBytes("President/Yasinsac_Vice President/Andel~3");
                byteSent = sender.Send(messageSent);

                while (true)
                {
                    byteRecv = sender.Receive(messageReceived);
                    if (byteRecv > 0)
                    {
                        break;
                    }
                }


                // Close Socket using
                // the method Close()

                sender.Shutdown(SocketShutdown.Both);
                sender.Close();
            }

            // Manage of Socket's Exceptions
            catch (ArgumentNullException ane)
            {

                Console.WriteLine("ArgumentNullException : {0}", ane.ToString());
            }

            catch (SocketException se)
            {

                Console.WriteLine("SocketException : {0}", se.ToString());
            }

            catch (Exception e)
            {
                Console.WriteLine("Unexpected exception : {0}", e.ToString());
            }
        }

        catch (Exception e)
        {

            Console.WriteLine(e.ToString());
        }
    }
}