# Pharus

![Wemos](/images/pharus_logo.png)

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

The project was implemented under the "Augmented Reality" program created by the Pilecki Institute. The basic idea of the project was to elevate perceiving art beyond the existing techniques - local exhibitions, talks, or lectures, where in times of social distancing, their organization was difficult and in some cases impossible.
The idea behind the project is the original description of Open Call:

“The sudden closure of museums, theaters, cinemas, the cancellation of concerts and meetings with authors posed many questions to the audience - participants and creators, managers, animators, researchers and educators about how to operate despite the imposed restrictions and forced them to seek new solutions. Restrictions affect not only the reception but also force the reorganization of the existing forms of activity. Ideas for a digital leap into the future are multiplying, lazily postponed for years. "

As part of this idea, the Pharus project was created. From Latin, it means "lantern" which directly refers to its function. It aimed to create a tool that would allow the transfer of information beyond the classic forms of communication, centralized around one space, but not directly using modern media such as the Internet / Facebook / Instagram, but using the technological achievements of modern times to the maximum.
The designed device, based on the ESP32 microcontroller, allows creating a local "beacon" that gives its own WiFi access point. Logging in from your phone to this network automatically (using the captive portal functionality) redirects the user to a website that contains content and functionalities stored only on the SD card connected to the device.

This solution is based on existing technologies, however, it stands out with a few details. The first thought is a QR code that redirects to specific websites. Unlike this technology, the project does not require any additional applications to read the code, redirects are automatic, without need for additional link clicks, and independent of Internet access. The second thought is a commercial beacon system, used, for example, in museums. The thing that distinguishes the project from such ready-made applications is that you can achieve goals without the use of external applications or expensive devices, significantly extending the range of usage for less commercial installations.

In terms of technology, the project is based on current IoT solutions. The project uses the Lolin32 lite prototype board, together with an external microSD card reader, to create a hotspot after connecting to which, a user is redirected to a website located on the card connected to the device. In addition, the project provides for 3 types of power supply - mains power (via 5V charger), battery power (using 18650 batteries, using a built-in battery charging system), and solar power (in the case of long-term use in spaces that do not have access to mains power). To extend possibilities of usage, the project involves the design of a 3D printed case, that can withstand rain and dust in outdoor scenarios.

The project is aimed at a very wide group of artists or organizations. It can be used by individual creators as well as smaller or larger festivals. The project can be implemented once (for a limited time) or it can be implemented as a permanent installation.

The project includes a couple of scenarios that have been divided into 3 layers - base scenarios, gamification scenarios, and event scenarios.

The first level represents the simplest way to use the device. It allows you to add a substantive comment in normally inaccessible places, to disperse the visiting by taking the content outside one space, or to divide the content and spread it over a specific expanse.

The second level introduces gamification scenarios. Based on the functionality of the base scenarios, it adds collecting, leveling, or city game elements to increase the attractiveness of the event.

The third level, based on gamification solutions, aimed mainly at festivals or organizations, is based on adding physical and digital rewards after achieving specific goals.

Of course, the listed scenarios are not final, the possibilities of use are unlimited and the listed scenarios are only examples of use.

## 2. Hardware

### 2.1 Basic assumptions

As a base idea of distributing project as CC-BY, that is available for as many people as possible, with different technical knowledge, it generates some assumptions that should be met for it to be useful.

#### 2.1.1 Ease of configuration and mounting

The first assumption is the ability to use and deploy devices with as many people and organizations as possible. Since many of these people would not have any technical background, this project aims to be as easy to deploy as possible, but without cutting usability.

This means, the device is constructed with modules, with as low amount of soldering possible, uses globally available components.

Programming should also be easy, step by step solution, wherein easiest scenarios will not require any programming knowledge.

#### 2.1.2 Price

The device is trying to keep its overall price as low as possible. For individual creators and smaller organizations cost of production of a single device at 100 euro might be too big or that sum of money could be used more wisely. The overall cost of a single device, in full setup, when bought on AliExpress will be at around 15 euro.

#### 2.1.3 Components availability

All components are globally available and can be replaced with alternatives.

#### 2.1.4 User friendly scenario

The idea of this solution is to make connections as easy as possible. That excludes any apps, complicated configuration, and connection. A user connects to a Wi-Fi access point (created by the microcontroller), opens the browser, and enters an address.

The best way would be to be redirected automatically to the desired local address (through captive portal) but it doesn't work with HTTPS.

#### 2.1.5 Universal installation

The project allows the installation of a device in many ways, indoor and outdoor. Energy can be provided with a power supply (standard cell phone charger), USB port in any device, batteries, and solar power.

### 2.2 Components

List of all components needed to assembly device, with extra information useful while ordering parts.

| Component | Description | Photo | USB Power Qty | Battery Power Qty | Solar Power Qty |
| --- | --- | --- | :---: | :---: | :---: |
| Wemos Lolin32 lite | Main microcontroller. It's has been replaced with D32 or D32 Pro (which are slightly larger), but is still widely available | ![Wemos](/images/Wemos_lolin32.jpg) | 1 | 1 | 1 |
| Card reader | Most basic card reader working on SPI. Be aware of power supply - some of them have built-in stabilizer 5V/3.3V and might work with microcontrollers without external 5V power supply. Card reader used in this project (and fitting into 3D printed enclosure is 18.5 mm width. Also, aim with one without pre-soldered connectors | ![Card_reader](/images/SD_card_reader.jpg) | 1 | 1 | 1 |
| microSD card | Use any low storage (under 32 Gb) SDHC card. Speed is not important in this project. SD cards (such as 1 or 2Gb might, or might not work). | ![Card](/images/SD_card.jpg) | 1 | 1 | 1 |
| USB cable | Any micro USB type B cable, standard for most smartphones, preferred length of 1.5m | ![USB Cable](/images/USB_cable.jpg) | 1 | Only for upload | 1 |
| Batteries | These are standard 18650 batteries widely used in many applications. Do not believe in ultra-high capacities. For the longest working time choose original batteries like sony with 2250 mAh. It's the best solution when batteries are the only power source so four of these can support power for over 100 hours. With solar power, you can settle with cheap ones (mine are 1800 mAh- tested) and cost 1/3 of the original price  | ![18650](/images/18650.jpg) | 0 | 4 | 2/4 |
| Battery holders | Any most basic battery holders, smaller the better, just to allow an easy wire-to-wire connection. | ![Battery_holder](/images/battery_holder.jpg) | 0 | 4 | 2/4 |
| Battery connectors | JST PH2.0 2PIN. Be aware of colors and +/- on the Lolin board since they might not match with red and black colors on connectors (and reversing polarity will fry battery charging controller | ![Battery_connectors](/images/JST_2PIN.jpg) | 0 | 1 | 1 |
| Wires | I've been using 28AWG wires, but any would fit, smaller diameter is better for more flexibility | ![Wires](/images/wires.jpg) | 0 | 1 | 1 |
| Solar power | Any solar panel 5-6V and between 2 to 3 W. Maximum charging current is 500 mA. Also, solar panels cannot be cheap - 2 euro solar panel won't be 2W. First of all check solar panel size - it should be at least 11x11 cm to provide enough power | ![Solar_Panel](/images/solar_panel.jpg) | 0 | 0 | 1 |
| Zip ties | Zip ties for holding two pieces of a case together. You need a single 350x5mm zip tie or multiple shorter ones. | ![Zip ties](/images/zip_ties.jpg) | Only with case | Only with case | Only with case |
| Heat shrink tubes | Or other insulation for soldered wires of batteries holders. For joining 4 wires you need 5/2.5mm and for 2 wires 4/2mm. | ![Shrink tubes](/images/shrink_tubes.jpg) | 0 |  4 cm |  4 cm |
| Filament | Any filament that suits your preferred printing style | ![Wires](/images/filament.jpg) | Only with case | Only with case | Only with case |

### 2.3 Tools and machines

List of tools required for this project.

| Tool | Description | Photo | Optional/Necessary |
| --- | --- | --- | --- |
| Soldering iron | Any soldering iron, preferably with a small tip (for accuracy) | ![Soldering_iron](/images/soldering_iron.jpg) | Necessary |
| Solder Wire | Lead-free soldering iron | ![Soldering_wire](/images/solder_wire.jpg) | Necessary |
| Knife | Upholstery knife or any other for stripping wires. You can also use wire stripper but due to small diameters and a small amount of stripped wire it's easier to use a knife | ![Knife](/images/knife.jpg) | Necessary |
| Generic 3D printer | Used for printing weatherproof case | ![3D printer](/images/3D_printer.jpg) | Optional |

### 2.4 Connection schematics

The device can be connected in 3 possible ways, that depend on a possible power source.

#### 2.4.1 Local power supply

In this case, no solar panels or batteries are needed.

![Schematics](/images/ps_schematics.png)

#### 2.4.2 Batteries

To maintain 3 days operation it is recommended to attach at least 4 batteries.

![Schematics](/images/battery_schematics.png)

#### 2.4.3 Solar panel

For a constant solar panel power supply, it is recommended to attach at least 2 batteries - this allows to last at least one day of bad weather.

![Schematics](/images/solar_schematics.png)

## 3. Software

### 3.1 Principle

The main functionality of the software is to:
- create a WiFi access point
- create a DNS server
- create Asynchronous Web Server
- access files on a microSD card

This way user, after connecting to a WiFi network and opening the browser will be redirected to the local webserver. All files for this webserver are hosted on a microSD card.

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


This part is self-explanatory. It's starting serial communication, initializing SD card (and printing of what is on that card), and starting Wi-Fi Access Point and DNS server. You can change `WiFi.softAP("Pharus");` to your desired hotspot name.

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


This is an important part. Client requesting empty will be given index.html file from SD card. For other files, requesting for example "/image.jpg" will load "image.jpg" from the SD card. Each server.on can be copied and modified to allow adding extra files that can be read from the SD card. In the end, we call a new handler that will load the main index.html file. All is finished by starting a web service.

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


Loop only checks for incoming requests to redirect them to the local address. It's not the best solution (but the only one available right now) - it does not redirect from HTTPS so it's not very useful with modern websites and browsers - but since it does nothing bad, and in some cases of HTTP addresses redirects to webserver - so this part is left to be.

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

The last function lists all files on the SD card.

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

All files must be placed directly on the SD card. They cannot be placed in any other folder and need to have specific names:

| File name | Description | Mandatory |
| --- | --- | --- |
| index.html | Main HTML file, webpage | Yes |
| style.css | CSS file with styles | No |
| background.jpg | Background image for better visual reception | No |
| image1.jpg | First of four available image files supported by ESP code | No |
| image2.jpg | Second of four available image files supported by ESP code | No |
| image3.jpg | Third of four available image files supported by ESP code | No |
| image4.jpg | Fourth of four available image files supported by ESP code | No |
| movie.mp4 | Movie file available to be included on webpage | No |
| sound.mp3 | Sound file available to be included on webpage | No |

Be aware, that image files must be saved as jpg, not jpeg.

There is no limit on the size of files, but be aware that this is not a high-speed connection. 100 Mb video file will load in a very long time, but will not play continuously, since transfer speed is to low. Stick with small files. After uploading files test with your phone if it works smoothly. If not, compress files.

## 4. How to use

This section will explain how to use this device - both from the creator (organizer) and visitor perspective.

### 4.1 Creator

1. Choose your scenario. Think about how you want to use, where, what content you want to deliver. You can use example scenarios or think of something new. Some ideas can be found in section 5. Scenarios.

2. After creating a scenario, choose the right hardware solution. Use the following diagram to determine what hardware to use in each location:

![How_to](/images/Hardware_diagram.png)

3. Gather all required media - images, movies, sounds, and texts. Prepare HTML files and media files according to examples, required formats, and data structure. Detailed information is in sections 3.3 SD card files structure and 7.4 Using example files

4. Assemble hardware (section 7.1 Connections), upload software (section 7.3 Configuring Arduino IDE, compiling and uploading sketch) and eventually print and assemble case (7.6 Assembling case).

5. When all devices are ready, place them at chosen locations.

6. Now you need to let your visitors know about it. It can be done in different ways, but the simplest way would be to use social media posts. You need to inform your guests about a few things:
  - that this solution is available and they can get extra content by using their phones
  - step by step solution (like the one below) how to exactly connect
  - locations of devices - you can just post address, pin on online maps, or you can add geocaching solutions by posting geographical coordinates, or even a picture of a certain place in the city. You can also start a city game scenario by showing the location of the first device and putting the rest of the locations on subsequent devices.

### 4.2 Visitor

1. After arriving in the location indicated by the organizer, bring up available WiFi networks.

![How_to](/images/How_to_user_1.jpg)

2. Connect to WiFi with name described in the event

![How_to](/images/How_to_user_2.jpg)

3. You should see a popup that will say "Sign in to a WiFi network" or similar, based on your smartphone

![How_to](/images/How_to_user_3.jpg)

4. Click on popup or network name again to be redirected to a local website with the desired content.

![How_to](/images/How_to_user_4.jpg)

5. In rare cases that captive portal is not compatible with your smartphone, bring up a web browser and enter 192.168.4.1

![How_to](/images/How_to_user_5.jpg)

## 5. Scenarios

This project involves three levels of usage scenarios. Each level is more complex and has its designated use.

1. The First level are basic scenarios - these are the most common and simplest form us using a device. Generally, they are used to deliver extra content without squeezing visitors within a single room. Most basic forms include delivering single or multiple photos, text, video, or audio, but they are not limited to it.
2. Second level are gamification scenarios - their purpose is to increase the engagement of users. They require more advanced technical solutions, but with the right scenarios and ideas can greatly increase the involvement of visitors, leave them with a better experience, and supply organizers with extra tools.
3. Third level are event solutions - these are mostly festival/organization scenarios that are based around increasing involvement using gamification and external motivation with real-world awards.

### 5.1 Basic Scenarios

Basic scenarios are the first step in delivering content to the recipient. They represent the simplest and most standard applications of the device.

Three sub scenarios can be included in its usage:

#### 5.1.1 Substantive comment

This scenario allows adding extended explanation, comment, history fact, author biography to a presented art piece when no other forms are available. It would apply mostly to historical points, big scale installations, urban art, murals, or mappings, where scale or location do not allow to add a printed description, or it would be easily missed.

Examples of use:

- big scale mural, placed in an urban environment, have no way of including information about the artist and/or comment about the painting itself. Even if there is a possible way to place it, with such a scale it will be missed by visitors, which will take some space between the facade and viewing area. Connecting to a device will allow them to get this extra information on their phones.
- placing informational boards on historical buildings or monuments might not be possible. The device placed in its close perimeter will allow sharing facts, photos, or other extra information about its origin, or important people who lived there.
- large scale installation or video mapping during the festival will be hard to comment on, or at least present the author, because any informational slate will be lost in its scale. Using the device will allow delivering all information that could be shared, like artist bio, commentary, photos or movies of construction, etc.

#### 5.1.2 Scattered content

Scattering content allows taking art outside of the exhibition area. Multiple devices located in different places (within the city, country, or even globally), allows to scatter visitors and apply more social distancing in terms of art delivery. Each device will deliver single artwork in digital form. Scattering also allows moving some forms of art to places with more ambience.

Example of use:

- painter or graphic that creates landscape or urban architectural drawings/paintings can deliver his artworks exactly in places where they were created.
- sound artist or musician can move his creations to places with a better atmosphere or vibe, that can improve reception.
- any artist can place devices in public spaces or bars, as a form of expression or self-promotion.

#### 5.1.3 Extended content

Extended content is similar to a substantive comment, but instead of delivering comments or other text, it will deliver other art in digital form. It would fit in galleries, or at art exhibitions, where limited space (or budget) does not allow to put extra artworks.

Example of use:

- gallery with limited space can only display a few paintings out of series. The device can be used to present other paintings in digital form.
- emerging artist, instead of only his illustrations would like to show also his digital movies. Setting up for example 4 TV or projectors require equipment that he has no access to, and is above his budget in case of renting or buying. Setting up devices allows him to present his other work budget-wise way.
- musician or artist can set the device in a local restaurant/bar/pub where he hanged a poster about his event and add extra involvement and deliver more information.

### 5.2 Gamification

Gamification scenarios are the next level of device use. Based on basic scenarios they are used to liven up the experience of visiting galleries/festivals. They are an intermediate element between classical marketing and non-commercial promotion. They allow to extend events in time and increase visitor engagement, which has an application both to individual artists planning to set up bigger exhibitions, and festivals trying to increase their guests' activity.

Even due highly recommended, basic scenarios do not require any other external elements. Gamification scenarios must include at least social media posts to guide the guest to the required spaces.

Gamification is the usage of game elements or game creation techniques, in areas not connected to gaming. Its goal is to increase activity, motivate, stimulate learning, and problem-solving. By using internal and external motivation, it puts users into intense interaction with the event.

Including gamification in process of exhibitions allows to:
- extend the time of exhibition/festival,
- adds extra engagement,
- provides additional tools for the social media team,
- increase activity in less frequented parts of the festival.

Possible scenarios are unlimited and many game mechanics can be transferred, for example:
- collecting elements
- ratings
- goals
- increasing experience/levels
- badges
- solving riddles
- storytelling

Since there is a lot of possible applications, only a few will be shown with an example.

#### 5.2.1 Collecting

Collecting elements increase the user's activity, because each element of the collection have a bigger value than a single one. People are naturally conditioned to fill holes and complete patterns, so that’s why a person that has not visited all sites at the festival, will go to the last one, just to complete the collection.

This scenario allows users to visit multiple destinations, log into each one of them, and because of logging in, collect part of the reward. This could be:
- wallpaper
- badge (all collection of badges)
- experience points
- artwork
- story

The main idea of it is to cut one single element into multiple parts, so the user can experience filling each part as an accomplishment.

Example of use:

- festival is spread into six locations - each holding its own exhibition or event. Setting devices in each one of these places and connecting to them will gradually reveal wallpaper to be download. This could convince some users to visit a remote location that otherwise would be omitted.
- individual artist can set up devices in multiple places, and by posting information about their locations on social media (for example one every 3 days), increase visitor's activity, keep the event alive for a longer time and finally reward the active visitors with a digital piece of art.
- organization or artist could spread devices around the city, and implementing a geocaching mechanism (by posting geographical coordinates or even photos of these places) could activate visitors to participate more intensely in the event.

#### 5.2.2 Levelling

Designed to rather lightweight events, this scenario is based on collecting experience points instead of parts of the collection. It can provide deeper involvement - except for collecting elements, it includes a psychological element of progress and achievements. But due to the fact that it is clearly a gaming solution, it might not be interesting to some groups of visitors and even lower the rank of event, so it should be used carefully, and it fits more into "fun" festivals or activates designed for a younger audience.

Example of use:

- summer festival could set the device at each music stage, and change it for every artist allowing to collect as much event from the festival as possible, and award points (which will fill the progress bar to the next level). It would allow a user to brag around social media and increase the number of tagged posts.
- medieval festival could use multiple devices and by letting kids connect and gather experience points, will award them with the more powerful avatar, from example starting with standard infantry to a knight in shining armour. Each level would consist of a new illustration and historical information.

#### 5.2.3 Riddles solving

It can improve both leveling and collecting by adding a more advanced element of solving any kind of riddles. This could greatly benefit storytelling scenarios.

Examples of use:
- after logging in, the user is given part of the story. He has also a window to enter a reply to a question, concerning the surrounding location. After a proper answer, he will be revealed with another part. All devices around the city are part of one story.
- kids at the museum, after logging into the network, and before being able to level up, are required to answer a question with a piece of knowledge that can be found around the perimeter, which will stimulate learning.

### 5.3 Event scenarios

Event scenarios are the last level of engagement for visitors and are plainly a commercial form of rewarding activity. They are purely based on gamification scenarios that add extra, real world prizes. They should be thoroughly considered since making them too easy (or easy to cheat) with too big of a reward could have a disastrous impact on the event budget or at least public relations.

Since basically all gamification solutions could be applied, there are no sub-scenarios.

Some examples of how to include real-world prizes include:
- setting up hard storytelling/riddle city hunting, and collecting whole story (along with control codes) could be awarded a personal meeting with the main artist during the festival,
- festival lasts for a week. During that week there are several events, that guests can participate in. Going to every event and logging in, will generate a discount code for the last main event. Or allow for one free drink.
- just arriving at the music festival and logging in will result in participating in a draw for some merch.

## 6. Weatherproof Case

This project also includes a 3D printable case for components and batteries. Two versions are available - housing 2 and 4 batteries. The up arrow on the upper part shows the direction in which case should be mounted to maintain assumed IP33 weather resistance. The case also has compartments for holding spare SD cards - depending on a version from one to three extra cards.

Base ideas:
- weather resistance as IP33 - when mounted upright, electronics will be protected against rain and dust. The weak point is cable passthrough. It is left big to pull the micro USB connector without the need to cut the wire. It can be upgraded to IP68 by using silicone or glue.
- hard case - all walls are thick so it will protect electronics from physical damage
- steady mounting - batteries and ESP will have minimal movement to minimalize disconnections and shortcuts.
- closing should be as simple as possible - no screws or mechanisms - joining part would be accomplished by zip ties.
- low aesthetics - the case is not supposed to be pretty - it's always hidden and does not require to look good. It should be functional.
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

These instructions show step by step connection when using a 3D printed case. If you are not planning to use a 3D printed case, you can connect the device with another length of cables, or even using headers and jumper cables.

1. Cut 6 pieces of wires each 10 cm. Strip about 2mm from both ends.

![Connections](/images/connections_1.jpg)

2. Solder wires to lolin32 from the bottom side of the board. Solder them to pins GND, 3.3V, 19, 20 23, 18, 5.

![Connections](/images/connections_2.jpg)

3. Solder another end of the wires to microSD card module, according to schematics.

![Connections](/images/connections_3.jpg)

4. Guide battery holder wires from bottom to right corner of batteries holder and then to the top. Guide top wires through the middle of the batteries pack and cut them just at the edge of batteries cases. Strip about 5mm from the end. If you are having problems with keeping cases together you can place batteries in and squeeze them with zip ties. Be extra careful for black and red wires not to touch each other.

![Connections](/images/connections_4.jpg)

![Connections](/images/connections_5.jpg)

5. Cut about 3 cm from JST connectors, strip them for about 5mm. Solder all battery and JST wires together. Do not forget to put on heat shrinking tubes and shrink them on soldered connections to insulate them. Check wires polarity with microcontroller board - if red wires are not connecting to **+** on the Lolin board, then switch wires in connectors.

![Connections](/images/connections_6.jpg)

6. Cut USB connector from a USB cable. Strip about 3 cm of main insulation, then cut out all extra wires except black and red. Stip the end of these wires for about 3mm.

![Connections](/images/connections_7.jpg)

7. Solder USB cable to the back of the solar panel. Red cable goes to **+**, black to **-**.

![Connections](/images/connections_8.jpg)

8. Secure wires with power tape.

![Connections](/images/connections_9.jpg)

9. Connect batteries to batteries JST socket, and plug USB connector to a USB socket on the Lolin board.

![Connections](/images/connections_10.jpg)

### 7.2 Arduino IDE, ESP, and libraries

This project will require to use of Arduino IDE to compile and upload code, with ESP32 boards and external libraries

#### 7.2.1 Installing Arduino IDE

Follow instructions on the official Arduino guide:

https://www.arduino.cc/en/guide/windows

#### 7.2.2 Installing ESP32 boards

This is an easy step by step solution on how to install ESP32 boards in Arduino IDE.

1) Open Arduino IDE
2) Click on **File** > **Preferences**
3) Under **Additional Boards Manager URLs** paste a link to Espressif boards manager *https://dl.espressif.com/dl/package_esp32_index.json*
4) Click **OK**
5) Go to **Tools** > **Board** > **Boards Manager**
6) Search for *ESP32*
7) Press the install button for the *ESP32 by Espressif Systems*
8) After few seconds it should be installed, after this click **Close**

#### 7.2.3 Installing required libraries

This project requires Asynchronous Web Server libraries. It consists of two packages:

- [ESPAsyncWebServer!](https://github.com/me-no-dev/ESPAsyncWebServer/archive/master.zip)
- [AsyncTCP!](https://github.com/me-no-dev/AsyncTCP/archive/master.zip)

Download both .zip packages and change their names by removing *-master* from the end of the filename.

Next:
1. Open Arduino IDE
2. Go to **Sketch** > **Include Library** > **Add .ZIP Library...**
3. Choose one of the downloaded libraries and click open
4. Repeat for the second library

### 7.3 Configuring Arduino IDE, compiling and uploading a sketch

After this, you are ready to upload software to the microcontroller. First, you need to setup Arduino IDE for proper settings.
1. Connect your Lolin32 board to the computer using a USB cable.
2. Open Arduino IDE
3. Go to **Tools** > **Boards:"XXXXXX"** > **ESP32 Arduino**  and choose *WEMOS LOLIN32*
4. Go to **Tools** > **Upload speed: "XXXXXX"** and choose *921600* or if it's not working try *115200*
5. Go to **Tools** > **CPU Frequency: "XXXXXX"** and choose *240 Mhz (WiFi/BT)*
6. Go to **Tools** > **Flash Frequency: "XXXXXX"** and choose *80 Mhz*
7. Go to **Tools** > **Partition Scheme: "XXXXXX"** and choose *No OTA (Large APP)*
8. Go to **Tools** > **Port: "XXXXXX"** and choose port COM that is connected to ESP32 board. If it is hard for you to decide which one is it, disconnect the board, and check which one of the COM ports disappeared. Connect again and this will be the right port to choose.

Next, download the Augumented_Reality.ino project file.

Open it in Arduino IDE. If prompted that file should be inside a folder of the same name, click yes.

Now there is only one thing that you can or should do. On line 34 there is code that creates name for WiFi access point - `WiFi.softAP("esp-captive");`. Change `esp-captive` it to your desired access point name. If the range of multiple microcontrollers could or will overlap, each one of them requires a unique name.

After that click the round button with right facing arrow **Upload**. This will compile and upload code to the microcontroller.

### 7.4 Using example files

After setting up ESP32, you need to prepare SD card and project files. These instructions present way of editing or creating HTML files that will work directly with the device, without a need to change the C++ code on ESP, and are based on examples provided.

#### 7.4.1 Basic scenarios

##### Text

Create any, simple HTML file. To format it, you can use for example https://html-online.com/editor/. Save it as index.html and place it directly on the SD card.

or

Open index.html file in HTML_examples/Basic_scenarios/text folder with notepad. Edit out *EDIT THIS TITLE*, *EDIT THIS HEADER* and *Lorem ipsum* to your desired text. Save it as index.html. You can add a background file as background.jpg. If you do not add a background file, the background will be black and the text will be white.

Place both index.html and background.jpg (optionally - you can skip this file) directly on the SD card.

##### Image

Use index.html file in HTML_examples/Basic_scenarios/image. Copy it to SD card and add your desired image file, saved in jpg format and name it image1.jpg. The image will be displayed to fill the screen area. The remaining space will black.

You can use Windows Paint or any other graphic editor to save the file as a jpg.

##### Image gallery

Use index.html file in HTML_examples/Basic_scenarios/image_gallery. Copy it to SD card and add your desired image files (maximum of four), saved in jpg format, and named as image1.jpg, image2.jpg, etc. Images will be displayed as 2x2 grid miniatures with a black background. Clicking miniatures will display a full-sized version.

You can use Windows Paint or any other graphic editor to save the file as a jpg.

##### Movie

Use index.html file in HTML_examples/Basic_scenarios/movie. Copy it to an SD card and add your desired movie file in mp4 format and name it movie.mp4. The file will be loaded as a playable movie.

If your movie is not in an mp4 file format, you can use any online video converter, for example, https://www.freeconvert.com/. In the video converters click on to mp4 and upload your video.

##### Sound

Use index.html file in HTML_examples/Basic_scenarios/sound. Copy it to the SD card and add your desired sound file in mp3 format and name it sound.mp3.
You can also add an image (saved as image1.jpg) as a cover photo.
The file will be loaded as a playable sound.

If your sound is not in mp3 format, you need to convert it. Again you can use https://www.freeconvert.com/.

##### Advanced

This example mixes different media types on a single webpage. It includes:
- 5 sections, each with text and header,
- 4 of these sections contain a different image (packed as a single sprite file),
- 1 section with sound,

First, you need to prepare image sprite files. This will include all 4 images for each section within a single file. For this, using any image editor create a single file that is 500x2000 pixels. Save it as image1.jpg. Next prepare four files that you want to use - they need to be square - scale and crop them to 500x500 pixels each. Copy and paste each image to previously created image1.jpg - and paste them from top to bottom, each one under previous. The top image will be displayed under section 1, second under section 2, etc.

Prepare all other media files as described in previous examples.

In the HTML file change all Lorem Ipsum fragments and section titles to your desired descriptions.

Be aware that you are limited to a maximum of 5 files loaded simultaneously. Sometimes event this is not enough to prevent the device from restarting. When using multiple files test the device and keep all files as lightweight as possible.

#### 7.4.2 Gamification

##### Image collecting

This example allows showing a whole image by connecting to six devices. Each device will reveal one part of an image.

Select your image and save it as image1.jpg on an SD card. Copy index.html file from HTML_examples/Gamification/Image_collecting to SD card.

Get next SD card, copy your image and index.html file. Edit html file and on line 9 change from `localStorage.part1 = "1";` to `localStorage.part2 = "1";`

Do the same for the next SD cards, increasing part number on each one until you reach six. Put each SD card in each device and place them in selected locations.

##### XP Collecting

This is a basic example of collecting experience from six different devices. Logging to the first one will award 100 XP points. On 300 points user will reach the next level and be awarded a new avatar with a new description. Reaching 600 points will reach the maximum level with the last avatar.

To use this example first you need to prepare your images. All must be square (1:1 Aspect ratio) with the same resolution. Next prepare the sprite file, by changing the first image vertical resolution to three times its height and then copy each next down under. In other words, prepare a single file out of 3 files by putting them on a grid. For example, if your files are 700x700 pixels, then prepare a file that is 700x2100 pixels, and put the first image so it's left upper corner coordinates would be 0,0, second 0,700, and third 0,1400. Save image as image1.jpg

Now edit index.html file located in HTML_examples/Gamification/XP_collecting. There are a few lines to edit.

On line 68 after line 'document.getElementById("description").innerHTML = ' change text inside quotation marks to you desired description. This is the text for first level. Next do the same on lines 73 and 78 for level second and third respectively.

Copy both image1.jpg and index.html to the first SD card.

Get a second card and again copy both image.jpg and index.html. Edit index.html.

On line 10 change from `if (!localStorage.part1){` to `if (!localStorage.part2){` and on line 25 change from `localStorage.part1 = 1;` to `localStorage.part2 = 1;`.

Do the same for the rest of the SD cards. Put each SD card in each device and place them in selected locations.

##### Riddles

This example uses an image collecting scenario with an added question/answer input form to let users through. After logging into the device user will see a question, input field for an answer, and submit button. After entering the wrong answer (strings are case insensitive), and clicking the "Answer" button text "Wrong answer" will appear below the submit button. On the correct answer, an overlay will disappear and the collected fragment will be shown. It is also spread across 6 devices.

Select your image and save it as image1.jpg on an SD card. Copy index.html file from HTML_examples/Gamification/Riddles to SD card.

Edit index.html and change on line 54 change inside of header `<h1></h1>` to your desired question and on line 11 change `var correct_answer = ""` change to your desired answer.

Get next SD card, make previous changes on lines 54 and line 11 and also on line 19 change `localStorage.part1 = "1";` to `localStorage.part2 = "1";`. 

Do the same for next SD cards, increasing part number on each one until you reach six. Put each SD card in each device and place them in selected locations.

#### 7.4.3 Event scenarios

This example consists of two file types - one index.html is copied on an SD card, the second verification.html is used to check if the generated code is correct.

In each folder (named device_1 to device_4) there is a single index.html. Each file should be copied to a different SD card and placed in a different set.

For each device add one image1.jpg file.

The user after logging into each device will get one portion of a two-digit numeral code. It means logging to all 4 devices will generate a random 8 digit code. After getting all 4 devices script will generate 2 more numbers - these are simple checksum or verification numbers. These last 2 digits are generated based on previous randomly generated digits.

The whole, 10 digit code can be manually transferred to verification.html to check whether the code is correct or not.

Warning - this example is quite easy to hack, it's not encrypted in any way and can be cheated on (by sharing codes). It is recommended not to use this example in money sensitive cases (like merch giveaway, free entries, or discounts). Use it as a scenario example for further development or for digital rewards.

### 7.5 Testing

After modifying and preparing example files put your SD card in the SD card module. Open Arduino IDE (no need to open any file - just start Arduino IDE). Connect microcontroller to your computer and set proper COM port (just like during uploading). Go to **Tools** and choose **Serial Monitor**. In the lower right corner change baud to 115200. Click the reset button on a microcontroller (right between battery and USB connectors). The board should restart and should report it's start up on Serial Monitor.

First, it will report the SD card status. If everything is successful, it should print out files from the SD card. If not, It will report "Card Mount Failed" and restart after few seconds. This could happen just after soldering and first-time use of the SD card and SD card module. Try restarting, plugging, and unplugging the microcontroller, and SD card a few times until it's mounted. After that, there won't be any problem with mounting.

Next microcontroller will start the WiFi access point and report it's IP address that will be 192.168.4.1

Get your phone and connect to a WiFi network created by a microcontroller. In your browser enter 192.168.4.1 and see if your webpage is working the desired way.

If there are some problems with a webpage, you are using any collecting scenarios and you want to go back to the primordial state (just like freshly connecting new phone) clean cookies and web stored pages in your smartphone.

### 7.6 Assembling case

1. Guide USB wire through the opening in the bottom case.

![Case assembly](/images/case_assembly_1.jpg)

2. Put two pieces of 3d printed stoppers around the cable. You can do it from inside (more secure, but a bit tricky) or from the bottom.

![Case assembly](/images/case_assembly_2.jpg)

3. Place Lolin board in it slot, connectors upward, with electronics facing batteries compartment. Next put the microSD card module in its slot, again with electronics facing the batteries compartment. After this, connect micro-USB to the Lolin board, and pull it down so there is no loose cable in the compartment.

![Case assembly](/images/case_assembly_3.jpg)

4. Put batteries in the battery compartment, and connect wires to battery socket on Lolin board.

![Case assembly](/images/case_assembly_4.jpg)

5. Insert the microSD card in the microSD card module. You can store extra microSD cards in side compartments.

![Case assembly](/images/case_assembly_5.jpg)

6. Cover all with the top piece of 3D printed case. Correct wires guiding if the case can't close completely.

![Case assembly](/images/case_assembly_6.jpg)

7. Use a zip tie to secure both parts of the case. You can use side handles to zip tie the case to environmental elements like tree branches or poles.

![Case assembly](/images/case_assembly_7.jpg)


## 8. Notes

- all files used in HTML examples are licensed under CC-0 licenses.
- while creating HTML pages, you cannot use more than 5 files that are loaded at the same time. If you need to load more files you can:
    - use css image sprites,
    - include styles inside index.html
    - pack scripts into single gz files or include them in the index.html file.
- keep all media as lightweight as possible - transfer rates are not great and sometimes even image sprites are not enough to prevent device restart during download.
- event example is quite easy to hack, it's not encrypted in any way and can be cheated on (by sharing codes). It is recommended not to use this example in money sensitive cases (like merch giveaway, free entries, or discounts). Use it as a scenario example for further development or for digital rewards.
