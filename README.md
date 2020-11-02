# Pharus

## Table of Content

- [1. Idea](#1-idea)
- [2. Hardware](#2-hardware)
  - [2.1 Basic assumptions](#21-basic-assumptions)
  - [2.2 Components](#22-components)
  - [2.3 Tools and machines](#23-tools-and-machines)
  - [2.4 Connection schematics](#24-connection-schematics)
- [3. Software](#3-software)
  - [3.1 Principle](#31-principle)
  - [3.2 Code](#32-code)
  - [3.3 SD card files structure](#33-sd-card-files-structure)
- [4. How to use](#4-how-to-use)
  - [4.1 Creator](#41-creator)
  - [4.2 Visitor](#42-visitor)
- [5. Scenarios](#5-scenarios)
  - [5.1 Basic Scenarios](#51-basic-scenarios)
  - [5.2 Gamification](#52-gamification)
  - [5.3 Event scenarios](#53-event-scenarios)
- [6. Weatherproof Case](#5-weatherproof-case)
  - [6.1 Parts](#61-parts)
  - [6.2 Printer setup](#62-printer-setup)
- [7. Step by step setup example](#7-step-by-step-setup-example)
  - [7.1 Connections](#71-connections)
  - [7.2 Arduino IDE, ESP and libraries](#72-arduino-ide-esp-and-libraries)
  - [7.3 Configuring Arduino IDE, compiling and uploading sketch](#73-configuring-arduino-ide-compiling-and-uploading-sketch)
  - [7.4 Using example files](#74-using-example-files)
  - [7.5 Testing](#75-testing)
  - [7.6 Assembling case](#76-assembling-case)
- [8. Notes](#8-Notes)

## 1. Idea

Project was implemented under the "Augmented Reality" program created by the Pilecki Institute. The basic idea of the project was to elevate of perceiving art beyond the existing techniques - local exhibitions, talks or lectures, where in times of social distancing, their organization was difficult and in some cases impossible.

The idea behind the project is the original description of Open Call:

“The sudden closure of museums, theaters, cinemas, the cancellation of concerts and meetings with authors posed many questions to the audience - participants and creators, managers, animators, researchers and educators about how to operate despite the imposed restrictions and forced them to seek new solutions. Restrictions affect not only the reception, but also force the reorganization of the existing forms of activity. Ideas for a digital leap into the future are multiplying, lazily postponed for years. "

As part of this idea, the Pharus project was created. From Latin it means "lantern" which directly refers to its function. Its aim was to create a tool that would allow the transfer of information beyond the classic forms of communication, centralized around one space, but not directly using modern media such as the Internet / Facebook / Instagram, but using the technological achievements of modern times to the maximum.

Designed device, based on the ESP32 microcontroller, allows to create a local "beacon" that gives its own WiFi access point. Logging in from your phone to this network automatically (using the captive portal functionality) redirects the user to a website that contains content and functionalities stored only on the SD card connected to the device.

This solution is based on existing technologies, however, it stands out with a few details. The first thought is QR code that redirect to specific websites. Unlike this technology, the project does not require any additional applications to read the code, redirects are automatic, without need for additional link clicks, and independent of Internet access. The second thought is commercial beacon system, used, for example, in museums. The thing that distinguishes the project from such ready-made applications is that you can achieve goals without the use of external applications or expensive devices, significantly extending the range of usage for less commercial installations.

In terms of technology, the project is based on current IoT solutions. The project uses the Lolin32 lite prototype board, together with an external microSD card reader, to create a hotspot after connecting to which, user is redirected to a website located on the card connected to the device. In addition, the project provides for 3 types of power supply - mains power (via 5V charger), battery power (using 18650 batteries, using a built-in battery charging system), and solar power (in the case of long-term use in spaces that do not have access to mains power). To extend possibilities of usage, project involves design of 3D printed case, that can withstand rain and dust in outdoor scenarios.

The project is aimed at a very wide group of artists or organizations. It can be used by individual creators as well as smaller or larger festivals. The project can be implemented once (for a limited time) or it can be implemented as a permanent installation.

The project includes a couple of scenarios that have been divided into 3 layers - base scenarios, gamification scenarios, and event scenarios.

The first level represents the simplest way to use the device. It allows you to add substantive comment in normally inaccessible places, to disperse the visiting by taking the content outside one space, or to divide the content and spread it over a specific expanse.

The second level introduces gamification scenarios. Based on the functionality of the base scenarios, it adds collecting, leveling or city game elements to increase the attractiveness of the event.

The third level, based on gamification solutions, aimed mainly at festivals or organizations, is based on adding physical and digital rewards after achieving specific goals.

Of course, the listed scenarios are not final, the possibilities of use are unlimited and the listed scenarios are only examples of use.


## 2. Hardware

### 2.1 Basic assumptions

As a base idea of distributing project as CC-BY, that is available for as many people as possible, with different technical knowledge, it generates some assumptions that should be met for it to be useful.

#### 2.1.1 Ease of configuration and mounting

First assumption is ability to use and deploy device with as many people and organisations as possible. Since many of these people would not have any technical background, this project aims to be as easy to deploy as possible, but without cutting usability.

This means, device is constructed with modules, with as low amount of soldering possible, uses globally available components.

Programming should also be easy, step by step solution, where in easiest scenarios will not require any programming knowledge.

#### 2.1.2 Price

Device is trying to keep it's overall price as low as possible. For individual creators and smaller organisations cost of production single device at 100 euro might be to big or that sum of money could be used more wisely. Overall cost of single device, in full setup, when bought on AliExpress will be at around 15 euro.

#### 2.1.3 Components availability

All components are globally available, and can be replaced with alternatives.

#### 2.1.4 User friendly scenario

Idea of this solution is to make connections as easy as possible. That excludes any apps, complicated configuration and connection. User connects to Wi-Fi access point (created by microcontroller), opens browser and enters address.

Best way would be to be redirected automatically to desired local address (through captive portal) but it doesn't work with HTTPS.

#### 2.1.5 Universal installation

Project allows installation of device in many ways, inside and outside. Energy can be provided with power supply (standard cell phone charger), USB port in any device, batteries and solar power.

### 2.2 Components

List of all components needed to assembly device, with extra information useful while ordering parts.

| Component | Description | Photo | USB Power Qty | Battery Power Qty | Solar Power Qty |
| --- | --- | --- | :---: | :---: | :---: |
| Wemos Lolin32 lite | Main microcontroller. It's has been replaced with D32 or D32 Pro (which are slightly larger), but is still widely available | ![Wemos](/images/Wemos_lolin32.jpg) | 1 | 1 | 1 |
| Card reader | Most basic card reader working on SPI. Be aware of power supply - some of them have built in stabilizer 5V/3.3V and might work with microcontroller without external 5V power supply. Card reader used in this project (and fitting into 3D printed enclosure is 18.5 mm width. Also aim with one without presoldered connectors | ![Card_reader](/images/SD_card_reader.jpg) | 1 | 1 | 1 |
| microSD card | Use any low storage (under 32 Gb) SDHC card. Speed is not important in this project. SD cards (such as 1 or 2Gb might, or might not work). | ![Card](/images/SD_card.jpg) | 1 | 1 | 1 |
| USB cable | Any microUSB type B cable, standard for most smartphones, preffered lenght of 1.5m | ![USB Cable](/images/USB_cable.jpg) | 1 | Only for upload | 1 |
| Batteries | These are standard 18650 batteries widely used in many application. Do not believe ultra high capacities. For longest working time choose original batteries like sony with 2250 mAh. It's best solution, when batteries are only power source so four of these can support power for over 100 hours. With solar power you can settle with cheap ones (mine are 1800 mAh- tested) and cost 1/3 of original price  | ![18650](/images/18650.jpg) | 0 | 4 | 2/4 |
| Battery holders | Any most basic battery holders, smaller the better, just to allow easy wire-to-wire connection. | ![Battery_holder](/images/battery_holder.jpg) | 0 | 4 | 2/4 |
| Battery connectors | JST PH2.0 2PIN. Be aware of colors and +/- on Lolin board since they might not match with red and black colors on connectors (and reversing polarity will fry battery charging controller | ![Battery_connectors](/images/JST_2PIN.jpg) | 0 | 1 | 1 |
| Wires | I've been using 28AWG wires, but any would fit, smaller diameter is better for more flexibility | ![Wires](/images/wires.jpg) | 0 | 1 | 1 |
| Solar power | Any solar panel 5-6V and between 2 to 3 W. Maximum charging current is 500 mA. Also solar panels cannot be cheap - 2 euro solar panel won't be 2W. First of all check solar panel size - it should be at least 11x11 cm to provide enough power | ![Solar_Panel](/images/solar_panel.jpg) | 0 | 0 | 1 |
| Zip ties | Zip ties for holding two pieces of case together. You need single 350x5mm zip tie, or multiple shorter ones. | ![Zip ties](/images/zip_ties.jpg) | Only with case | Only with case | Only with case |
| Heat shrink tubes | Or other insulation for soldered wires of batteries holders. For joining 4 wires you need 5/2.5mm and for 2 wires 4/2mm. | ![Shrink tubes](/images/shrink_tubes.jpg) | 0 |  4 cm |  4 cm |
| Filament | Any filament that suits your prefered printing style | ![Wires](/images/filament.jpg) | Only with case | Only with case | Only with case |

### 2.3 Tools and machines

List of tool required for this project.

| Tool | Description | Photo | Optional/Necessary |
| --- | --- | --- | --- |
| Soldering iron | Any soldering iron, preferably with small tip (for accuracy) | ![Soldering_iron](/images/soldering_iron.jpg) | Necessary |
| Solder Wire | Lead free soldering iron | ![Soldering_wire](/images/solder_wire.jpg) | Necessary |
| Knife | Upholstery knife or any other for stripping wires. You can also use wire stripper but due to small diameters and small amount of stripped wire it's easier to use knife | ![Knife](/images/knife.jpg) | Necessary |
| Generic 3D printer | Used for printing weatherproof case | ![3D printer](/images/3D_printer.jpg) | Optional |

### 2.4 Connection schematics

Device can be connected in 3 possible ways, that depends on possible power source.

#### 2.4.1 Local power supply

In this case, no solar panels or batteries are needed.

![Schematics](/images/ps_schematics.png)

#### 2.4.2 Batteries

To maintain 3 days operation it is recomended to attach at least 4 batteries.

![Schematics](/images/battery_schematics.png)

#### 2.4.3 Solar panel

For constant solar panel power supply it is recomended to attach at least 2 baterries - this allows to last at least one day of bad weather.

![Schematics](/images/solar_schematics.png)

## 3. Software

### 3.1 Principle

Main functionality of software is to:
- create WiFi access point
- create DNS server
- create Asynchronous Web Server
- access files on microSD card

This way user, after connecting to WiFi network and opening browser will be redirected to local webserver. All files for this webserver are hosted on microSD card.

### 3.2 Code

Include libraries

	#include <DNSServer.h>
	#include <WiFi.h>
	#include <AsyncTCP.h>
	#include "ESPAsyncWebServer.h"
	#include "SD.h"
	#include <Wire.h>

Declare DNS server and Web Server

	DNSServer dnsServer;
	AsyncWebServer server(80);

Declare new handler class

	class CaptiveRequestHandler : public AsyncWebHandler {
	  public:
	    CaptiveRequestHandler() {}
	    virtual ~CaptiveRequestHandler() {}

	    bool canHandle(AsyncWebServerRequest *request) {
	      //request->addInterestingHeader("CAPTIVE");
	      return true;
	    }

	    void handleRequest(AsyncWebServerRequest *request) {
	      Serial.println("Requested index.html");
	      request->send(SD, "/index.html", String(), false);
	    }
	};


This part is self-explanatory. It's starting serial communication, initializing SD card (with printing of what is on that card) and starting Wi-Fi Access Point and DNS server. You can change `WiFi.softAP("Pharus");` to your desired hotspot name.

	void setup() {
	  Serial.begin(115200);

	  // initialize SD card
	  Serial.println("::::SD::::");
	  if (!SD.begin()) {
	    Serial.println("Card Mount Failed");
	    delay(3000);
	    Serial.println("Restarting");
	    ESP.restart();
	  } else {
	    Serial.println("Card Mounted");
	  }
	  uint8_t cardType = SD.cardType();
	  Serial.print("Card type: ");
	  Serial.println(cardType);

	  listDir(SD, "/", 2);
	  Serial.println("::::/SD::::");
	  Serial.println("");

	  WiFi.softAP("Pharus");
	  dnsServer.start(53, "*", WiFi.softAPIP());
	  Serial.println(WiFi.softAPIP());


This is important part. Client requesting empty, will be given index.html file from SD card. For other files, requesting for example "/image.jpg" will load "image.jpg" from SD card. Each server.on can be copied and modified to allow adding extra files that can be read from SD card. At the end we call new handler that will load main index.html file. All is finished by starting web service.

	  server.on("/style.css", HTTP_GET, [](AsyncWebServerRequest * request) {
	    Serial.println("Requested style.css");
	    request->send(SD, "/style.css", "text/css");
	  });
	  server.on("/background.jpg", HTTP_GET, [](AsyncWebServerRequest * request) {
	    Serial.println("Requested background.jpg");
	    request->send(SD, "/background.jpg", "image/jpg");
	  });
	  server.on("/image1.jpg", HTTP_GET, [](AsyncWebServerRequest * request) {
	    Serial.println("Requested image1.jpg");
	    request->send(SD, "/image1.jpg", "image/jpg");
	  });
	  server.on("/image2.jpg", HTTP_GET, [](AsyncWebServerRequest * request) {
	    Serial.println("Requested image2.jpg");
	    request->send(SD, "/image2.jpg", "image/jpg");
	  });
	  server.on("/image3.jpg", HTTP_GET, [](AsyncWebServerRequest * request) {
	    Serial.println("Requested image3.jpg");
	    request->send(SD, "/image3.jpg", "image/jpg");
	  });
	  server.on("/image4.jpg", HTTP_GET, [](AsyncWebServerRequest * request) {
	    Serial.println("Requested image4.jpg");
	    request->send(SD, "/image4.jpg", "image/jpg");
	  });
	  server.on("/sound.mp3", HTTP_GET, [](AsyncWebServerRequest * request) {
	    Serial.println("Requested sound.mp3");
	    request->send(SD, "/sound.mp3", "sound/mp3");
	  });
	  server.on("/movie.mp4", HTTP_GET, [](AsyncWebServerRequest * request) {
	    Serial.println("Requested movie.mp4");
	    request->send(SD, "/movie.mp4", "movie/mp4");
	  });

	  server.addHandler(new CaptiveRequestHandler());

	  server.begin();
	}


Loop only checks for incoming requests to redirect them to local address. It's not the best solution (but only one available right now) - it do not redirect from HTTPS so it's not very useful with modern websites and browsers - but since it does nothing bad, and in some cases of HTTP addresses redirects to webserver - so this part is left to be.

	void loop() {
	  dnsServer.processNextRequest();
	}

	void listDir(fs::FS &fs, const char * dirname, uint8_t levels) {
	  Serial.printf("Listing directory: %s\n", dirname);

	  File root = fs.open(dirname);
	  if (!root) {
		Serial.println("Failed to open directory");
		return;
	  }
	  if (!root.isDirectory()) {
		Serial.println("Not a directory");
		return;
	  }

Last function lists all files on SD card.

	  File file = root.openNextFile();
	  while (file) {
		if (file.isDirectory()) {
		  Serial.print("  DIR : ");
		  Serial.println(file.name());
		  if (levels) {
			listDir(fs, file.name(), levels - 1);
		  }
		} else {
		  Serial.print("  FILE: ");
		  Serial.print(file.name());
		  Serial.print("  SIZE: ");
		  Serial.println(file.size());
		}
		file = root.openNextFile();
	  }
	}

### 3.3 SD card files structure

All files must be placed directly on SD card. They cannot be placed in any other folder and need to have specific names:

| File name | Description | Mandatory |
| --- | --- | --- |
| index.html | Main html file, webpage | Yes |
| style.css | CSS file with styles | No |
| background.jpg | Background image for better visual reception | No |
| image1.jpg | First of four available image files supported by ESP code | No |
| image2.jpg | Second of four available image files supported by ESP code | No |
| image3.jpg | Third of four available image files supported by ESP code | No |
| image4.jpg | Fourth of four available image files supported by ESP code | No |
| movie.mp4 | Movie file available to be included on webpage | No |
| sound.mp3 | Sound file available to be included on webpage | No |

Be aware, that image files must be saved as jpg, not jpeg.

There is no limit on size of files, but be aware that this is not a high speed connection. 100 mb video file will load in very long time, but will not play continuously, since transfer speed is to low. Stick with small files. After uploading files test with your phone if it works smoothly. If not, compress files.

## 4. How to use

This section will explain to actualy use this device - both from creator (organizer) and visitor perspective.

### 4.1 Creator



### 4.2 Visitor perspective

1. After arriving in location indicatet by organizer, bring up available WiFi networks.

2. Connect to WiFi with name described in event

3. You should see a popup that will say "Sign in to a WiFi network" or simmilar, based on your smartphone

4. Click on popup or network name again to be redirected to local website with desired content.

5. In rare cases that captive portal is not compatible with your smartphone, bring up web browser and enter 192.168.4.1

## 5. Scenarios

This project involves three level of usage scenarios. Each level is more complex, and have it's designated use.

1. First level are basic scenarios - these are most common and simplest form us using device. Generally they are used to deliver extra content without squeezing visitors within single room. Most basic forms include delivering single or multiple photos, text, video or audio, but they are not limited to it.
2. Second level are gamification scenarios - their purpose is to increase engagement of users. They require more advanced technical solutions, but with right scenarios and ideas can greatly increase involvement of visitors, leave them with better experience and supply organizers with extra tools.
3. Third level are event solutions - these are mostly festival/organisation scenarios that are based around increasing involvement using gamification and external motivation with real world awards.

### 5.1 Basic Scenarios

Basic scenarios are first step of delivering content to recipient. They represent the simplest and most standard applications of device.

Three sub scenarios can be included in its usage:

#### 5.1.1 Substantive comment

This scenario allows to add extended explanation, comment, history fact, author biography to presented art piece, when no other forms are available. It would apply mostly to historical points, big scale installations, urban art, murals, or mappings, where scale or location do not allow to add printed description, or it would be easily missed.

Examples of use:

- big scale mural, placed in urban environment, have no way of including information about artist and/or comment about painting itself. Even if there is possible way to place it, with such scale it will be missed by visitors, that will take some space between facade and viewing area. Connecting to device will allow them to get these extra information on their phones.
- placing informational boards on historical building or monuments might not be possible. Device placed in its close perimeter will allow to share facts, photos or other extra information about its origin, or important people who lived there.
- large scale installation or video mapping during festival will be hard to comment, or at least present the author, because any informational slate will be lost in its scale. Using device will allow to deliver all information that could be shared, like artist bio, commentary, photos or movies of construction etc.

#### 5.1.2 Scattered content

Scattering content allows to take art outside of exhibitions area. Multiple devices located in different places (within city, country or even globally), allows to scatter visitors and apply more social distancing in terms of art delivery. Each device will deliver single artwork in digital form. Scattering also allows to move some forms art to places with more ambience.

Example of use:

- painter or graphic that creates landscape or urban architectural drawings/paintings can deliver his artworks exactly in places where they were created.
- sound artist or musician can move his creations to places with better atmosphere or vibe, that can improve reception.
- any artist can place devices in public spaces or bars, as form of expression or self-promotion.

#### 5.1.3 Extended content

Extended content is similar to substantive comment, but instead of delivering comment or other text it will deliver other art in digital form. It would fit in galleries, or at art exhibitions, where limited space (or budget) do not allows to put extra artworks.

Example of use:

- gallery with limited space can only display few painting out of series. Device can be used to present other painting if digital form.
- emerging artist, instead of only his illustrations would like to show also his digital movies. Setting up for example 4 TV or projectors require equipment that he has no access to, and is above his budget in case of renting or buying. Setting up devices allows him to present his other work budget-wise way.
- musician or artist can set device in local restaurant/bar/pub where he hanged poster about his event and add extra involvement and deliver more information.

### 5.2 Gamification

Gamification scenarios are next level of device use. Based on basic scenarios they are used to liven up experience of visiting galleries/festivals. They are intermediate element between classical marketing and non-commercial promotion. They allow to extend events in time and increase visitor engagement, which have use both to individual artist planning to set up bigger exhibitions, and festivals trying to increase their guests activity.

Even due highly recommended, basic scenarios do not require any other external elements. Gamification scenarios must include at least social media posts to guide guest to required spaces.

Gamification is a usage of game elements or game creation techniques, in areas not connected to gaming. It's goal is to increase activity, motivate, stimulate learning and problem solving. By using internal and external motivation, it puts users into intense interaction with event.

Including gamification in process of exhibitions allows to:
- extend time of exhibition/festival,
- adds extra engagement,
- provides with additional tools for social media team,
- increase activity in less frequented parts of festival.

Possible scenarios are unlimited and many of games mechanics can be transferred, for example:
- collecting elements
- ratings
- goals
- increasing experience/levels
- badges
- solving riddles
- storytelling

Since there is a lot of possible applications, only few will be shown with example.

#### 5.2.1 Collecting

Collecting elements increase users activity, because each element of collection have bigger value then single one. People are naturally conditioned to fill holes and complete patterns, so that’s why person that has not visited all sites on festival, will go to last one, just to complete collection.

This scenario allows users to visit multiple destinations, log into each one of them and because of logging in, collect part of reward. This could be:
- wallpaper
- badge (all collection of badges)
- experience points
- artwork
- story

Main idea of it, is to cut one single element into multiple parts, so user can experience filling each part with as accomplishment.

Example of use:

- festival is spread into six locations - each holding it's own exhibition or event. Setting devices in each one of this places and connecting to them will gradually reveal wallpaper to be download. This could convince some users to visit remote location that otherwise would be omitted.
- individual artist can setup device in multiple places, and by posting information about their locations on social media (for example one every 3 days), increase visitors activity, keep event alive for longer time and finally reward active visitor with digital piece of art.
- organisation or artist could spread devices around the city, and by implementing geocaching mechanism (by posting geographical coordinates or even photos of these places) could activate visitors to participate more intensely in event.

#### 5.2.2 Levelling

Designed to rather lightweight events, this scenario is based on collecting experience points instead of parts of collection. It can provide deeper involvement - except of collecting elements, it includes psychological element of progress and achievements. But due to the fact that it is clearly gaming solution, it might not be interesting to some groups of visitors and even lower the rank of event, so it should be used carefully, and it fits more into "fun" festival or activates designed to younger audience.

Example of use:

- summer festival could set device at each music stage, and change it every artist allowing to collect as much event from festival as possible, and award points (which will fill progress bar to next level). It would allow user to brag around social media and increase number of tagged posts.
- medieval festival could use multiple devices and by letting kids connect and gather experience points, will award them with more powerful avatar, from example starting with standard infantry to knight in shining armour. Each level would consist of new illustration and historical information.

#### 5.2.3 Riddles solving

It can improve both levelling and collecting by adding more advanced element of solving any kind of riddles. This could greatly benefit in storytelling scenarios.

Examples of use:
- after logging in, user is given part of the story. He has also a window to enter reply for a question, concerning surrounding location. After proper answer, he will be revealed with another part. All devices around city are part of one story.
- kids at museum, after logging to network, and before being able to level up, are required to answer a question with piece of knowledge that can be found around perimeter, which will stimulate learning.

### 5.3 Event scenarios

Event scenarios are last level of engagement for visitors and are plainly commercial form of rewarding activity. They purly based of gamification scenarios that adds extra, real world prizes. They should be thoroughly considered, since making them to easy (or easy to cheat) with too big reward could have disastrous impact on event budget or at least public relations.

Since basicly all gamification solutions could be applied, there are no sub-scenarios.

Some examples how to include real world prizes include:
- setting up hard storytelling/riddle city hunting, and collecting whole story (along with control codes) could be awarded with personal meeting with main artist during festival,
- festival last for a week. During that week there are several events, that guest can participate in. Going to every event and logging in, will generate discount code for last main event. Or allow for one free drink.
- just arriving at music festival and logging in will result in participating in draw for some merch.

## 6. Weatherproof Case

This project also includes 3D printable case for components and batteries. Two version are available - housing 2 and 4 batteries. Up arrow on upper part shows direction in which case should be mounted to maintain assumed IP33 weather resistance. Case also have compartments for holding spare SD cards - depending on version from one to three extra cards.

Base ideas:
- weather resistance as IP33 - when mounted upright, electronics will be protected against rain and dust. Weak point is cable passthrough. It is left big to pull micro USB connector without need to cut the wire. It can be upgraded to IP68 by using silicone or glue.
- hard case - all walls are thick so it will protect electronics from physical damage
- steady mounting - batteries and ESP will have minimal movement to minimalize disconnections and shortcuts.
- closing should be as simple as possible - no screws or mechanisms - joining part would be accomplished by zip ties.
- low aesthetics - case is not supposed to be pretty - it's always hidden and do not require to look good. It should be functional.
- 3D printable - can be printed without advanced slicing - no supports, overhangs and so.

### 6.1 Parts

| Part name | Description | Photo | Print Qty |
| --- | --- | --- | --- |
| 2_batteries_lower_case | Bottom compartment part for 2 batteries setup | ![lower_case](/images/2b_lc.jpg) | 1 |
| 2_batteries_upper_case | Top compartment part for 2 batteries setup | ![upper_case](/images/2b_uc.jpg) | 1 |
| 4_batteries_lower_case | Bottom compartment part for 4 batteries setup | ![lower_case](/images/4b_lc.jpg) | 1 |
| 4_batteries_upper_case | Top compartment part for 4 batteries setup | ![upper_case](/images/4b_uc.jpg) | 1 |
| stopper | Blocking part fitted in lower part to block and tighten USB cable passthrough | ![stopper](/images/stopper.jpg) | 2 |

### 6.2 Printer setup

Basically, any settings and materials will be good for printing, so choose one best fitting your printer. Some suggested setting:
- 0.4mm nozzle
- 0.2 layer height
- 3 wall line count
- 4 bottom layers
- 3 top layers
- no support
- grid pattern infill with at least 20% density
- concentric top/bottom pattern
- any material, suggested PLA or ABS

## 7. Step by step setup example

### 7.1 Connections

These instructions show step by step connection when using 3D printed case. You you are not planning to use 3d printed case, you can connect device with otheer lenght of cables, or even using headers and jumper cables.

1. Cut 6 pieces of wires each 10 cm. Strip about 2mm from both ends.

![Connections](/images/connections_1.jpg)

2. Solder wires to lolin32 from the bottom side of the board. Solder them to pins GND, 3.3V, 19, 20 23, 18, 5.

![Connections](/images/connections_2.jpg)

3. Solder other end of the wires to microSD card module, according to schematics.

![Connections](/images/connections_3.jpg)

4. Guide battery holder wires from bottom to right corner of batteries holder and then to the top. Guide top wires through middle of bateries pack and cut them just at edge of batteries cases. Strip about 5mm from end. If you are having problems with keeping cases togheter you can place batteries in and squeeze them with zip ties. Be extra carefull for black and red wires not to touch each other.

![Connections](/images/connections_4.jpg)

![Connections](/images/connections_5.jpg)

5. Cut about 3 cm from JST connectors, strip them for about 5mm. Solder all battery and JST wires together. Do not forget to put on heat shrinking tubes and shrink them on soldered connections to insulate them. Check wires polarity with microcontroller board - if red wires are not connecting to **+** on lolin board, then switch wires in connectors.

![Connections](/images/connections_6.jpg)

6. Cut USB connector from USB cable. Strip about 3 cm of main insulation, then cut out all extra wires exept black and red. Stip end of these wires for about 3mm.

![Connections](/images/connections_7.jpg)

7. Solder USB cable to the back of solar panel. Red cable gos to **+**, black to **-**.

![Connections](/images/connections_8.jpg)

8. Secure wires with power tape.

![Connections](/images/connections_9.jpg)

9. Connect batteries to batteries JST socket, and plug USB connector to USB socket on lolin board.

![Connections](/images/connections_10.jpg)

### 7.2 Arduino IDE, ESP and libraries

This project will require to use Arduino IDE to compile and upload code, with ESP32 boards and external libraries

#### 7.2.1 Installing Arduino IDE

Follow instructions on official Arduino guide:

https://www.arduino.cc/en/guide/windows

#### 7.2.2 Installing ESP32 boards

This is easy step by step solution how to install ESP32 boards in Arduino IDE.

1) Open Arduino IDE
2) Click on **File** > **Preferences**
3) Under **Additional Boards Manager URLs** paste link to Espressif boards manager *https://dl.espressif.com/dl/package_esp32_index.json*
4) Click **OK**
5) Go to **Tools** > **Board** > **Boards Manager**
6) Search for *ESP32*
7) Press install button for the *ESP32 by Espressif Systems*
8) After few seconds it should be installed, after this click **Close**

#### 7.2.3 Installing required libraries

This project requires Asynchronous Web Server libraries. It consist of two packages:

- [ESPAsyncWebServer!](https://github.com/me-no-dev/ESPAsyncWebServer/archive/master.zip)
- [AsyncTCP!](https://github.com/me-no-dev/AsyncTCP/archive/master.zip)

Download both .zip packages and change their names by removing *-master* from the end of filename.

Next:
1. Open Arduino IDE
2. Go to **Sketch** > **Include Library** > **Add .ZIP Library...**
3. Choose one of downloaded libraries and click open
4. Repeat for second library

### 7.3 Configuring Arduino IDE, compiling and uploading sketch

After this you are ready to upload software to microcontroller. First you need to setup Arduino IDE for proper settings.
1. Connect you Lolin32 board to computer using USB cable.
2. Open Arduino IDE
3. Go to **Tools** > **Boards:"XXXXXX"** > **ESP32 Arduino**  and choose *WEMOS LOLIN32*
4. Go to **Tools** > **Upload speed: "XXXXXX"** and choose *921600* or if it's not working try *115200*
5. Go to **Tools** > **CPU Frequency: "XXXXXX"** and choose *240 Mhz (WiFi/BT)*
6. Go to **Tools** > **Flash Frequency: "XXXXXX"** and choose *80 Mhz*
7. Go to **Tools** > **Partition Scheme: "XXXXXX"** and choose *No OTA (Large APP)*
8. Go to **Tools** > **Port: "XXXXXX"** and choose port COM that is connected to ESP32 board. You it's hard for you to decide which one is it, disconnect board, and check which one of COM ports disappeared. Connect again and this will be right port to choose.

Next download Augumented_Reality.ino project file.

Open it in Arduino IDE. If prompted that file should be inside folder of the same name, click yes.

Now there is only one thing that you can or should do. On line 34 there is code that creates name for WiFi access point - `WiFi.softAP("esp-captive");`. Change `esp-captive` it to your desired access point name. If range of multiple microcontroller could or will overlap, each one of them require unique name.

After that click round button with right facing arrow **Upload**. This will compile and upload code to microcontroller.

### 7.4 Using example files

After setting up ESP32, you need to prepare SD card and project files. These instructions presents way of editing or creating HTML files that will work directly with device, without a need to change C++ code on ESP, and are based on examples provided.

#### 7.4.1 Basic scenarios

##### Text

Create any, simple HTML file. To format it, you can use for example https://html-online.com/editor/. Save it as index.html and place it directly on SD card.

or

Open index.html file in HTML_examples/Basic_scenarios/text folder with notepad. Edit out *EDIT THIS TITLE*, *EDIT THIS HEADER* and *Lorem ipsum* to your desired text. Save it as index.html. You can add background file as background.jpg. If you do not add background file, background will be black and text will be white.

Place both index.html and background.jpg (optionally - you can skip this file) directly on SD card.

##### Image

Use index.html file in HTML_examples/Basic_scenarios/image. Copy it to SD card and add your desired image file, saved in jpg format and name it image1.jpg. Image will be displayed to fill the screen area. Remaining space will black.

You can use Windows Paint or any other graphic editor to save file as jpg.

##### Image gallery

Use index.html file in HTML_examples/Basic_scenarios/image_gallery. Copy it to SD card and add your desired image files (maximum of four), saved in jpg format and named as image1.jpg, image2.jpg etc. Images will be displayed as 2x2 grid miniatures with black background. Clicking miniatures will display full sized version.

You can use Windows Paint or any other graphic editor to save file as jpg.

##### Movie

Use index.html file in HTML_examples/Basic_scenarios/movie. Copy it to SD card and add your desired movie file in mp4 format and name it movie.mp4. File will be loaded as playable movie.

If your movie is not in mp4 file format, you can use any online video converter, for example https://www.freeconvert.com/. In video converters click on to mp4 and upload your video.

##### Sound

Use index.html file in HTML_examples/Basic_scenarios/sound. Copy it to SD card and add your desired sound file in mp3 format and name it sound.mp3.
You can also add an image (saved as image1.jpg) as cover photo.
File will be loaded as playable sound.

If your sound is not in mp3 format, you need to convert it. Again you can use https://www.freeconvert.com/.

##### Advanced

This example mixes different media types in single webpage. It includes:
- 5 sections, each with text and header,
- 4 of these sections contain different image (packed as single sprite file),
- 1 section with sound,

First you need to prepare image sprite files. This will include all 4 images for each section within single file. For this, using any image editor create single file that is 500x2000 pixels. Save it as image1.jpg. Next prepare four files that you want to use - they need to be square - scale and crop them to 500x500 pixels each. Copy and paste each image to previously created image1.jpg - and pase them from top to bottom, each one under previous. Top image will be displayed under section 1, second under section 2 etc.

Prepare all other media files as described in previous examples.

In HTML file change all Lorem Ipsum fragments and section titles to your desired descriptions.

Be aware that you are limited to maximum of 5 files loaded simultaneously. Sometimes event this is not enough to prevent device restarting. When using multiple files test device and keep all files as lightweight as possible.

#### 7.4.2 Gamification

##### Image collecting

This example allows to show whole image by connecting to six devices. Each device will reveal one part of image.

Select your image and save it as image1.jpg on SD card. Copy index.html file from HTML_examples/Gamification/Image_collecting to SD card.

Get next SD card, copy your image and index.html file. Edit html file and on line 9 change from `localStorage.part1 = "1";` to `localStorage.part2 = "1";`

Do the same for next SD cards, increasing part number on each one until you reach six. Put each SD card in each device and place them in selected locations.

##### XP Collecting

This is basic example for collecting experience from six different devices. Logging to first one will award 100 XP points. On 300 points user will reach next level and be awarded new avatar with new description. Reaching 600 points will reach maximum level with last avatar.

To use this example first you need to prepare your images. All must be square (1:1 Aspect ratio) with the same resolution. Next prepare sprite file, by changing first image vertical resolution to three times its height and then copy each next down under. In other words, prepare single file out of 3 files by putting them on grid. For example, if your files are 700x700 pixels, then prepare file that is 700x2100 pixels, and put first image so it's left upper corner coordinates would be 0,0, second 0,700 and third 0,1400. Save image as image1.jpg

Now edit index.html file located in HTML_examples/Gamification/XP_collecting. There are few lines to edit.

On line 68 after line 'document.getElementById("description").innerHTML = ' change text inside quotation marks to you desired description. This is the text for first level. Next do the same on lines 73 and 78 for level second and third respectively.

Copy both image1.jpg and index.html to first SD card.

Get second card and again copy both image.jpg and index.html. Edit index.html.

On line 10 change from `if (!localStorage.part1){` to `if (!localStorage.part2){` and on line 25 change from `localStorage.part1 = 1;` to `localStorage.part2 = 1;`.

Do the same for te rest of SD cards. Put each SD card in each device and place them in selected locations.

##### Riddles

This example uses image colleting scenario with added question/answer input form to let user through. After logging to device user will see question, input field for answer, and submit button. After entering wrong answer (strings are case insensitive), and clicking "Answer" button text "Wrong answer" will appear below the submit button. On correct answer, overlay will disapear and collected fragment will be shown. It is also spread across 6 devices.

Select your image and save it as image1.jpg on SD card. Copy index.html file from HTML_examples/Gamification/Riddles to SD card.

Edit index.html and change on line 54 change inside of header `<h1></h1>` to you desired question and on line 11 change `var correct_answer = ""` change to your desired answer.

Get next SD card, make previous changes on lines 54 and line 11 and also on line 19 change `localStorage.part1 = "1";` to `localStorage.part2 = "1";`. 

Do the same for next SD cards, increasing part number on each one until you reach six. Put each SD card in each device and place them in selected locations.

#### 7.4.3 Event scenarios

TBA

### 7.5 Testing

After modifying and preparing example files put your SD card in SD card module. Open Arduino IDE (no need to open any file - just start Arduino IDE). Connect microcontroller to your computer and set proper COM port (just like during uploading). Go to **Tools** and choose **Serial Monitor**. In lower right corner change baud to 115200. Click reset button on microcontroller (right between battery and USB connectors). Board should restart and should report it's start up on Serial Monitor.

First it will report SD card status. If everything is successful, it should print out files from SD card. If not, It will report "Card Mount Failed" and restart after few seconds. This could happen just after soldering and first time use of SD card and SD card module. Try restarting, plugging and unplugging microcontroller, and SD card few times until it's mounted. After that there won't be any problem with mounting.

Next microcontroller will start WiFi access point and report it's IP address that will be 192.168.4.1

Get your phone and connect to WiFi network created by microcontroller. In your browser enter 192.168.4.1 and see if your webpage is working desired way.

If there are some problems with webpage, you are using any collecting scenarios and you want to go back to primordial state (just like freshly connecting new phone) clean cookies and web stored pages in your smartphone.

### 7.6 Assembling case

1. Guide USB wire through opening in bottom case.

![Case assembly](/images/case_assembly_1.jpg)

2. Put two pieces of 3d printed stoppers around cable. You can do it from inside (more secure, but a bit tricky) or from the bottom.

![Case assembly](/images/case_assembly_2.jpg)

3. Place lolin board in it slot, connectors upward, with electronics facing batteries compartment. Next put microSD card module in its slot, again with electronics facing batteries compartment. After this, connect microUSB to lolin board, and pull it down so there are no loose cable in compartment.

![Case assembly](/images/case_assembly_3.jpg)

4. Put batteries in battery compartment, and connect wires to battery socket on lolin board.

![Case assembly](/images/case_assembly_4.jpg)

5. Insert microSD card in microSD card module. You can store extra microSD cards in side compartments.

![Case assembly](/images/case_assembly_5.jpg)

6. Cover all with top piece of 3D printed case. Correct wires guiding if case can't close completly.

![Case assembly](/images/case_assembly_6.jpg)

7. Use zip tie to secure both parts of case. You can use side handles to zip tie case to enviroment elements like tree branches or poles.

![Case assembly](/images/case_assembly_7.jpg)


## 8. Notes

- all files used in HTML examples are licensed under CC-0 licenses.
- while creating html pages, you cannot use more then 5 files that are loaded at the same time. If you need to load more files you can:
    - use css image sprites,
    - include styles inside index.html
    - pack scripts into single gz files or include them in index.html file.
- keep all media as lightweight as possible - transfer rates are not great and sometimes even image sprites are not enough to prevent device restart during download.


### 8.1 TODO

- create HTML file for events scenario
- describe HTML files for event scenario
- add ilustrations for scenarios
- grammar check
