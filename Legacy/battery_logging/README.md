## Battery logging

Code for logging battery voltage to google sheets.

Based on:

https://randomnerdtutorials.com/esp32-esp8266-publish-sensor-readings-to-google-sheets/

https://www.youtube.com/watch?v=5JIJO1swQPE

*UPDATE: It turns out that you need to connect input to pin that works on ADC1 not ADC2. After initialising WiFi all analog Read from ACD2 will have value of 4095. It works ok on ADC1.*

*UPDATE: For 4.12V on battery ESP reports 2512, for 3.84V it reports 2261. It can be used to plot voltage in time instead of just reported value.*

This setup will check basic battery life when not connected to any power source other then batteries (dual 18650). It writes data every 15 seconds to simulate heavy load.

Second circuit includes solar panel. It's located outside, in indirect sunlight, with only one battery, and reports it's status every minute. It reports both battery level and solar panel voltage.

*UPDATE: 3.64V of solar equals 1750. 0.65V equals 225.

### Setup
Few thing must be done to log data.
1. Available WiFi with connection to internet.
2. Created account and webhooks applet on IFTTT.
3. Physical connetions according to scheme.
4. Changed code (WiFi credentials and IFTTT URL resource).

### Connection diagram for battery test

![Battery logger diagram](/battery_logging/battery_logger_diagram.png)

### Connection diagram for solar test

![Solar logger diagram](/battery_logging/solar_logger_diagram.png)

### Basic operation

After powering up, ESP connects to local Wifi (predefined). After connecting it connenects to IFTTT and sends recived data from analogRead(). Next, IFTTT publish this data to google sheets with date, time and value.

Code will send direct analogRead() values to google sheet. Before connecting to IFTTT service, it will check if board is conneted to WiFi. If not, it will try to connect.

### Outcome

#### Dual 18650 battery without solar power with high load (4850 connection per day)

![Graph](/battery_logging/graph_battery_high_load.png)

Test of only battery powered solution with high load (connection every 15 seconds) gave final working time of almost 29 hours.
It started at 3,98 V and finally droped to 3,08V before finally turning off. After connecting to power source it immediately reconnected and continued to send data to IFTTT service.

#### Dual 18650 battery without solar power with low load (96 connection per day)

![Graph](/battery_logging/graph_battery_low_load.png)

Test of only battery powered solution with low load (around 100 visitors per day - one every 15 minutes).
Test gave similar results in terms how voltage acts, but electronics were turned on for 9 hours shorter when compered to high data logging. One more test with same enviroment is needed to check if these are working conditions, or it's batteries deterioration.

Another test showed that batteries lasted for over 39 hours. We can se on graph, that first test, had drastic drop in voltage at beggining. It suggest that batteries ware not fully loaded.

#### Compared results 

![Graph](/battery_logging/graph_battery_compared.png)

#### Single 18650 battery with 2W solar panel in shade

![Graph](/battery_logging/graph_solar_shaded.png)

Leaving solar panel in shade is not effecient. Single battery was enough for around 13 hours of work. Solar panel didn't do much, you can see that after dark (when solar panel voltage droped to zero) there was speed up in battery discharge, but it is similar to drop in case without solar power.. Probably 3,6V is not enough to load the battery.

Battery died around 2:00, and stayed off until next day morning sun hit solar panel directly. It lasted for arround hour of low power supply (top voltage on this solar panel is 7.2V while top value recorded was 4V), unitl it got into shade again, and supplied battery with power to last another hour.

#### Single 18650 battery with 2W solar panel in direct sunlight

![Graph](/battery_logging/graph_solar_sunny.png)

Device was placed outside (discharged) at around 2:00. It was left for the night and next checked ar 14:00. It has turned on due to power from solar panels, but it has not connected to wifi (probably low reception). After bringing it in to connect and later leaving outside it was working fine. Graph clearly shows when it became shaded and when night began. Next day we see when sun rose, then when it hit panel directly. It's was mild day with heat wave around 13:30 after which there was thunderstorm. Device was left outside. Next day was mild, up until 14:00 when it started raining. Device died around 2:30 and have not powered up, since it is still raining and there is no sun.

#### Conclusion

Even with solar power, due to mixed atmospheric condidtions, it is need to supply device with minimum 2 batteries.
