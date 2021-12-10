#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

std::vector<std::string> GetHostFileData();

int main()
{
    int choice = 0;
    std::ifstream hosts("C:\\Windows\\System32\\drivers\\etc\\hosts");
    std::string server_list[15] =
    {
        "0.0.0.0 pfmsqos.southafricanorth.cloudapp.azure.com",
        "0.0.0.0 pfmsqos.westeurope.cloudapp.azure.com",
        "0.0.0.0 pfmsqos.southcentralus.cloudapp.azure.com",
        "0.0.0.0 pfmsqos.japaneast.cloudapp.azure.com",
        "0.0.0.0 pfmsqos.japanwest.cloudapp.azure.com",
        "0.0.0.0 pfmsqos.northeurope.cloudapp.azure.com",
        "0.0.0.0 pfmsqos.westus.cloudapp.azure.com",
        "0.0.0.0 pfmsqos.westus2.cloudapp.azure.com",
        "0.0.0.0 pfmsqos.northcentralus.cloudapp.azure.com",
        "0.0.0.0 pfmsqos.eastus2.cloudapp.azure.com",
        "0.0.0.0 pfmsqos.eastus.cloudapp.azure.com",
        "0.0.0.0 pfmsqos.southeastasia.cloudapp.azure.com",
        "0.0.0.0 pfmsqos.centralus.cloudapp.azure.com",
        "0.0.0.0 pfmsqos.brazilsouth.cloudapp.azure.com",
        "0.0.0.0 pfmsqos.eastasia.cloudapp.azure.com"
    };

    do
    {
        system("cls");
        std::cout << "Enter choice for:\n";
        std::cout << "1. Set hosts file to get OCE servers on Halo Infinite\n";
        std::cout << "2. Set hosts file to default\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter choice here: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1: // Writing servers to file
            if (hosts.good())
            {
                std::vector<std::string> hosts_data = GetHostFileData();
                int arr_position = 0;
                bool FileAlreadyContainsServers = false;

                // Check the servers don't already exist in the file
                for (int i = 0; i < hosts_data.size(); i++)
                {
                    if (hosts_data[i] == server_list[arr_position])
                    {
                        FileAlreadyContainsServers = true;
                    }
                }

                if (!FileAlreadyContainsServers)
                {
                    std::ofstream output_hosts;
                    output_hosts.open("C:\\Windows\\System32\\drivers\\etc\\hosts", std::ios::app);
                    for (int i = 0; i < 15; i++)
                    {
                        if (i == 14)
                        {
                            output_hosts << server_list[i];
                        }
                        else if (i == 0)
                        {
                            output_hosts << "\n" << server_list[i] << "\n";
                        }
                        else
                        {
                            output_hosts << server_list[i] << "\n";
                        }
                    }
                    output_hosts.close();
                    std::cout << "\n\n\t\tServers have been written to host file.\n";
                }
                else
                {
                    std::cout << "\n\n\t\tHost file already contains the servers.\n";
                }
            }
            else
            {
                std::cout << "\n\n\t\tCOULD NOT OPEN HOSTS FILE\n";
                std::cout << "\t\tCheck that you don't currently have it open and then try again.\n";
            }
            break;
        case 2: // Reset file to default
            if (hosts.good())
            {
                int vec_position1 = 0;
                int arr_position = 0;
                std::vector<std::string> hosts_data = GetHostFileData();
                std::vector<std::string> new_hosts_data;

                for (int i = 0; i < hosts_data.size(); i++)
                {
                    if (hosts_data[i] != server_list[arr_position])
                    {
                        new_hosts_data.push_back(hosts_data[i]);
                    }
                    else
                    {
                        arr_position++;
                    }
                }

                if (!new_hosts_data.empty() && arr_position == 0)
                {
                    std::cout << "\n\n\t\tThere are no servers currently in the hosts file.\n";
                }
                else if (!new_hosts_data.empty())
                {
                    // Rewriting the hosts file with no servers
                    int last_spot = new_hosts_data.size() - 1;
                    std::ofstream out_hosts;
                    out_hosts.open("C:\\Windows\\System32\\drivers\\etc\\hosts", std::ios::trunc);
                    
                    for (int i = 0; i < new_hosts_data.size(); i++)
                    {
                        if (i == last_spot)
                        {
                            out_hosts << new_hosts_data[i];
                        }
                        else
                        {
                            out_hosts << new_hosts_data[i] << "\n";
                        }                        
                    }

                    std::cout << "\n\n\t\tHost file has been set back to default\n";
                    out_hosts.close();
                }
                else
                {
                    std::cout << "\n\n\t\tThere are no servers currently in the hosts file.\n";
                }
            }
            else
            {
                std::cout << "\n\n\t\tCOULD NOT OPEN HOSTS FILE\n";
                std::cout << "\t\tCheck that you don't currently have it open and then try again.\n";
            }
            break;
        case 3:
            break;
        default: break;
        }

        std::cout << "\n";
        system("pause");
    } while (choice != 3);    

    hosts.close();
}

std::vector<std::string> GetHostFileData()
{
    std::ifstream read_hosts;
    std::string line;
    std::vector<std::string> hosts_file_data;

    // Get hosts file info
    read_hosts.open("C:\\Windows\\System32\\drivers\\etc\\hosts");
    while (std::getline(read_hosts, line))
    {
        hosts_file_data.push_back(line);
    }
    read_hosts.close();

    return hosts_file_data;
}