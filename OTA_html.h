//html files readable
extern RTC_DATA_ATTR float RTC_calibration_bat;
//header file readable
const char html_header[] PROGMEM = R"=====(
<html><head><meta charset="UTF-8"><title>ESP-GPS-Logger</title>
 <style>
        .button {
            background-color: #04aa6d; /* Green */
            border: none;
            color: white;
            padding: 8px 20px;
            text-align: center;
            text-decoration: none;
            display: inline-block;
            font-size: 16px;
            margin: 4px 2px;
            cursor: pointer;
            border-radius: 8px;
        }
        .button_del {
            background-color: #ab7373; /* red */
            border: none;
            color: white;
            padding: 8px 20px;
            text-align: center;
            text-decoration: none;
            display: inline-block;
            font-size: 16px;
            margin: 4px 2px;
            cursor: pointer;
            border-radius: 8px;
        }
        #navbar,
        #navbar-menu {
            position: fixed;
            left: 0;
            right: 0;
        }

        :root {
            --navbar-bg-color: hsl(0, 0%, 15%);
            --navbar-text-color: hsl(0, 0%, 85%);
            --navbar-text-color-focus: white;
            --navbar-bg-contrast: hsl(0, 0%, 25%);
        }

        * {
            box-sizing: border-box;
            margin: 0;
            padding: 0;
        }

        body {
            height: 100vh;
            font-family: Arial, Helvetica, sans-serif;
            line-height: 1.6;
        }

        .container {
            max-width: 1000px;
            padding-left: 1.4rem;
            padding-right: 1.4rem;
            margin-left: auto;
            margin-right: auto;
        }

        #navbar {
            --navbar-height: 64px;
            height: var(--navbar-height);
            background-color: var(--navbar-bg-color);
            box-shadow: 0 2px 4px rgba(0, 0, 0, 0.15);
        }

        .navbar-container {
            display: flex;
            justify-content: space-between;
            height: 100%;
            align-items: center;
        }

        .navbar-item {
            margin: 0.4em;
            width: 100%;
        }

        .home-link,
        .navbar-link {
            color: var(--navbar-text-color);
            text-decoration: none;
            display: flex;
            font-weight: 400;
            align-items: center;
        }

        .home-link:is(:focus, :hover) {
            color: var(--navbar-text-color-focus);
        }

        .navbar-link {
            justify-content: center;
            width: 100%;
            padding: 0.4em 0.8em;
            border-radius: 5px;
        }

        .navbar-link:is(:focus, :hover) {
            color: var(--navbar-text-color-focus);
            background-color: var(--navbar-bg-contrast);
        }

        .navbar-logo {
            background-color: var(--navbar-text-color-focus);
            border-radius: 50%;
            width: 30px;
            height: 30px;
            margin-right: 0.5em;
        }

        #navbar-toggle {
            cursor: pointer;
            border: none;
            background-color: transparent;
            width: 40px;
            height: 40px;
            display: flex;
            align-items: center;
            justify-content: center;
            flex-direction: column;
        }

        .icon-bar {
            display: block;
            width: 25px;
            height: 4px;
            margin: 2px;
            background-color: var(--navbar-text-color);
        }

        #navbar-toggle:is(:focus, :hover) .icon-bar {
            background-color: var(--navbar-text-color-focus);
        }

        #navbar-toggle[aria-expanded="true"] .icon-bar:is(:first-child, :last-child) {
            position: absolute;
            margin: 0;
            width: 30px;
        }

        #navbar-toggle[aria-expanded="true"] .icon-bar:first-child {
            transform: rotate(45deg);
        }

        #navbar-toggle[aria-expanded="true"] .icon-bar:nth-child(2) {
            opacity: 0;
        }

        #navbar-toggle[aria-expanded="true"] .icon-bar:last-child {
            transform: rotate(-45deg);
        }

        #navbar-menu {
            top: var(--navbar-height);
            bottom: 0;
            opacity: 0;
            visibility: hidden;
        }

        #navbar-toggle[aria-expanded="true"] + #navbar-menu {
            background-color: rgba(0, 0, 0, 0.4);
            opacity: 1;
            visibility: visible;
        }

        .navbar-links {
            list-style: none;
            position: absolute;
            background-color: var(--navbar-bg-color);
            display: flex;
            flex-direction: column;
            align-items: center;
            left: 0;
            right: 0;
            margin: 1.4rem;
            border-radius: 5px;
            box-shadow: 0 0 20px rgba(0, 0, 0, 0.3);
        }

        #navbar-toggle[aria-expanded="true"] + #navbar-menu .navbar-links {
            padding: 1em;
        }

        @media screen and (min-width: 700px) {
            #navbar-toggle,
            #navbar-toggle[aria-expanded="true"] {
                display: none;
            }

            #navbar-menu,
            #navbar-toggle[aria-expanded="true"] #navbar-menu {
                visibility: visible;
                opacity: 1;
                position: static;
                display: block;
                height: 100%;
            }

            #navbar-toggle[aria-expanded="true"] #navbar-menu .navbar-links,
            .navbar-links {
                margin: 0;
                padding: 0;
                box-shadow: none;
                position: static;
                flex-direction: row;
                width: 100%;
                height: 100%;
            }
        }

        #esplogger {
            font-family: Arial, Helvetica, sans-serif;
            border-collapse: collapse;
            width: 100%;
        }

        #esplogger td,
        #esplogger th {
            border: 1px solid #ddd;
            padding: 8px;
        }

        #esplogger tr:nth-child(2n) {
            background-color: #f2f2f2;
        }

        #esplogger tr:hover {
            background-color: #ddd;
        }

        #esplogger th {
            padding-top: 12px;
            padding-bottom: 12px;
            text-align: left;
            background-color: #04aa6d;
            color: #fff;
        }
 </style>
 <meta name="viewport" content="width=device-width, initial-scale=1">
    <!--<meta name="description" content="ketwords" />-->
 </head><body><header id="navbar">
  <nav class="navbar-container container">
    <a href="/" class="home-link">
      <div class="navbar-logo"></div>
      ESP-GPS-T-Logger 
      </a>
    <button type="button" id="navbar-toggle" aria-controls="navbar-menu" aria-label="Toggle menu" aria-expanded="false">
      <span class="icon-bar"></span>
      <span class="icon-bar"></span>
      <span class="icon-bar"></span>
    </button>
    <div id="navbar-menu" aria-labelledby="navbar-toggle">
      <ul class="navbar-links">
        <li class="navbar-item"><a class="navbar-link" href='https://github.com/RP6conrad/ESP-GPS-Logger' target='_blank'>Github</a></li>
        <li class="navbar-item"><a class="navbar-link" href="/gpstc">GPSTC</a></li>
        <li class="navbar-item"><a class="navbar-link" href="/">Files</a></li>
        <li class="navbar-item"><a class="navbar-link" href="/archive_file">Archive Files</a></li>
        <li class="navbar-item"><a class="navbar-link" href="/archive_list">Archive List</a></li>
        <li class="navbar-item"><a class="navbar-link" href="/upload">Upload</a></li>
        <li class="navbar-item"><a class="navbar-link" href="/config">Configuration</a></li>
        <li class="navbar-item"><a class="navbar-link" href="/firmware">Firmware</a></li>
      </ul>
    </div>
  </nav>
</header>
<script>
    const navbarToggle = navbar.querySelector("#navbar-toggle"),
        navbarMenu = document.querySelector("#navbar-menu"),
        navbarLinksContainer = navbarMenu.querySelector(".navbar-links");
    let isNavbarExpanded = "true" === navbarToggle.getAttribute("aria-expanded");
    const toggleNavbarVisibility = () => {
        (isNavbarExpanded = !isNavbarExpanded), navbarToggle.setAttribute("aria-expanded", isNavbarExpanded);
    };
    navbarToggle.addEventListener("click", toggleNavbarVisibility), navbarLinksContainer.addEventListener("click", (a) => a.stopPropagation()), navbarMenu.addEventListener("click", toggleNavbarVisibility);

    function confirmdelete() {
        return !0 == confirm("Want to delete?");
    }
    window.addEventListener('DOMContentLoaded', (event) => {
    if ((location.pathname == "/")|(location.pathname == "/archive")) sortTable();
    });
    function sortTable() {
      var table, rows, switching, i, x, y, shouldSwitch;
      table = document.getElementById("esplogger");
      switching = true;
      while (switching) {
        switching = false;
        rows = table.rows;
        for (i = 1; i < (rows.length - 1); i++) {
          shouldSwitch = false;
          x = rows[i].getElementsByTagName("TD")[2];
          y = rows[i + 1].getElementsByTagName("TD")[2];
          if (x.innerHTML.toLowerCase() < y.innerHTML.toLowerCase()) {
            shouldSwitch = true;
            break;
          }
        }
        if (shouldSwitch) {
          rows[i].parentNode.insertBefore(rows[i + 1], rows[i]);
          switching = true;
        }
      }
    }
</script>
<br><br><br>
  )=====";

//Config Part
const char html_config_header[] PROGMEM = R"=====(
<FORM action='/configupload' method='post'>
    <table id='esplogger'>
        <tr>
            <th>Name</th>
            <th>Value</th>
            <th>Info</th>
        </tr>
  )=====";
void Drop_down_menu(int config_item,int value,String drop_text,String& webpage){
  webpage += "<option value='";
  webpage += String(value);
  if(config_item == value) webpage +="' selected>";else  webpage +="'>";
  webpage +=drop_text;
  webpage +="</option>\n"; 
  }
void Drop_down_menu(float config_item,float value,String drop_text,String& webpage){
  webpage += "<option value='";
  webpage += String(value);
  if(abs(config_item-value)<0.1) webpage +="' selected>";else  webpage +="'>";//check if float diff < 0.1 !!!
  webpage +=drop_text;
  webpage +="</option>\n"; 
  }  
//configfill the current config Info
void html_config(String& webpage){
  //ssid
  String ssid="\"" + String(config.ssid) + "\"";//problem with white space in SSID depends on position in webpage ???
  webpage += "<tr>\n<td>1st WiFi SSID</td><td>\n";
  webpage += "<input size='21' type='text' required name='ssid' value="+ssid+">\n";//input size 20->30 if SSID name exceeds input size, full name is not visible
  webpage += "</select>\n</td><td>Name of the primary WiFi-network to connect to</td>\n</tr>\n";  
   //password
  webpage += "<tr>\n<td>1st WiFi password</td><td>\n";
  webpage += "<input size='20' type='text' required name='password' value="+String(config.password)+">\n";
  webpage += "</select>\n</td><td>Password of the primary WiFi-network</td>\n</tr>\n"; 
  //ssid2
  String ssid2="\"" + String(config.ssid2) + "\"";//problem with white space in SSID depends on position in webpage ???
  webpage += "<tr>\n<td>2nd WiFi SSID</td><td>\n";
  webpage += "<input size='21' type='text' required name='ssid2' value="+ssid2+">\n";//input size 20->30 if SSID name exceeds input size, full name is not visible
  webpage += "</select>\n</td><td>Name of an optional secondary WiFi-network to look for, smartphone or club hotspot</td>\n</tr>\n";  
   //password2
  webpage += "<tr>\n<td>2nd WiFi password</td><td>\n";
  webpage += "<input size='20' type='text' required name='password2' value="+String(config.password2)+">\n";
  webpage += "</select>\n</td><td>Password of the secondary WiFi-network</td>\n</tr>\n"; 
  //cal_bat
  webpage += "<tr>\n<td>Battery calbration</td><td>\n";
  webpage += "<input size='4' type='number' required name='cal_bat' min='1' max='3' value="+String(RTC_calibration_bat)+" step='0.01'>\n";
  webpage += "</select>\n</td><td>Calibration multiplier to optimize battery voltage management accuracy</td>\n</tr>\n"; 
  //cal_speed 
  webpage += "<tr><td>Speed unit</td><td>\n<select id='cal_speed' name='cal_speed' type='number'>\n";
  if(config.cal_speed == 3.6) webpage += "<option value='3.60' selected>km/h</option>\n"; else webpage += "<option value=3.60>km/h</option>\n";
  if(config.cal_speed <2) webpage += "<option value='1.9438' selected>knots</option>\n"; else webpage += "<option value=1.9438>knots</option>\n";
  webpage += "</select>\n</td><td>Choose your preferred speed unit, km/h or knots</td>\n</tr>\n";
  //webpage += "</select>\n</td><td>cal_speed: is for the conversion from gps unit m/s to km/h (3.6)or knots (1.9438).</td>\n</tr>\n";
  //Auto detect gps bd rate and type
  webpage += "<tr>\n<td>GPS Type</td><td>\n<select id='GPS_Type' name='GPS_Type'>";
  Drop_down_menu(config.ublox_type,255,"AUTO_DETECT @ Boot",webpage);
  Drop_down_menu(config.ublox_type,M8_9600BD,"M8@9600BD",webpage);
  Drop_down_menu(config.ublox_type,M8_38400BD,"M8@38400BD",webpage);
  Drop_down_menu(config.ublox_type,M8_115200BD,"M8@115200BD",webpage);
  Drop_down_menu(config.ublox_type,M9_9600BD,"M9@9600BD",webpage);
  Drop_down_menu(config.ublox_type,M9_38400BD,"M9@38400BD",webpage);
  Drop_down_menu(config.ublox_type,M9_115200BD,"M9@115200BD",webpage);
  Drop_down_menu(config.ublox_type,M10_9600BD,"M10@9600BD",webpage);
  Drop_down_menu(config.ublox_type,M10_38400BD,"M10@38400BD",webpage);
  Drop_down_menu(config.ublox_type,M10_115200BD,"M10@115200BD",webpage);
  webpage += "</select>\n</td><td>Choose GPS chipset-type and baudrate or set to auto detect</td>\n</tr>\n";
  //sample_rate
  webpage += "<tr>\n<td>Log rate</td><td>\n<select id='sample_rate' name='sample_rate'>";
  Drop_down_menu(config.sample_rate,1,"1 Hz",webpage);
  Drop_down_menu(config.sample_rate,2,"2 Hz",webpage);
  Drop_down_menu(config.sample_rate,4,"4 Hz",webpage);
  Drop_down_menu(config.sample_rate,5,"5 Hz",webpage);
  Drop_down_menu(config.sample_rate,8,"8 Hz",webpage);
  Drop_down_menu(config.sample_rate,10,"10 Hz",webpage);
  if(((config.ublox_type == M9_9600BD)|(config.ublox_type == M9_38400BD))|((config.ublox_type == M10_9600BD)|(config.ublox_type == M10_38400BD))){//&(config.gnss==1)
    Drop_down_menu(config.sample_rate,15,"15 Hz",webpage);
    Drop_down_menu(config.sample_rate,20,"20 Hz",webpage);
    }
  webpage += "</select>\n</td><td>Choose 5Hz for good accuracy / filesize ratio. <br> Choose up to 10Hz in standard mode and up to 20Hz for M8 / M9 in performance mode. Higher rates produce larger the files at higher CPU load. <br> One UBX NavPVT message is 100byte, log file size at 1Hz = 360kb/hour, at 10Hz = 3.6Mb/hour!<br>The M10's maximum sample-rates depend on GNSS settings: 4 GNSS : max  4 Hz, 3 GNSS : max 5 Hz, 2 GNSS : max 10 Hz !</td>\n</tr>\n";
  //cpu_freq
  webpage += "<tr>\n<td>CPU frequency</td><td>\n<select id='CPU_freq' name='CPU_freq'>";
  Drop_down_menu(config.cpu_freq,40,"40 MHz",webpage);
  Drop_down_menu(config.cpu_freq,80,"80 MHz",webpage);
  Drop_down_menu(config.cpu_freq,160,"160 MHz",webpage);
  Drop_down_menu(config.cpu_freq,240,"240 MHz",webpage);
  webpage += "</select>\n</td><td>Choose 80MHz for optimal performance / battery-life ratio. CPU clock settings may limit possible log rates.<br> Maximum log rate at 40MHz CPU = 2 Hz, at 80MHz CPU = 5Hz, at 160MHz CPU = 10hz and at 240MHz CPU = 20Hz.</td>\n</tr>\n";
  //gnss
  webpage += "<tr><td>GPS systems</td><td>\n<select id='gnss' name='gnss'>\n";
  if((config.ublox_type == M8_9600BD)|(config.ublox_type == M8_38400BD)|(config.ublox_type == M8_115200BD)){
      Drop_down_menu(config.gnss,0,"GPS + BEIDOU",webpage);
      }
  else{ 
      Drop_down_menu(config.gnss,1,"GPS + GALILEO",webpage);     
      }
  Drop_down_menu(config.gnss,2,"GPS + GLONASS",webpage);
  Drop_down_menu(config.gnss,3,"GPS + GLONASS + GALILEO",webpage);
  Drop_down_menu(config.gnss,4,"GPS + GALILEO + BEIDOU",webpage);      
  if((config.ublox_type == M9_9600BD)|(config.ublox_type == M9_38400BD)|(config.ublox_type == M9_115200BD)|(config.ublox_type == M10_9600BD)|(config.ublox_type == M10_115200BD)){
    Drop_down_menu(config.gnss,5,"GPS + GLONASS + GALILEO + BEIDOU",webpage);
    }   
  webpage += "</select>\n</td><td>For M10 choose 3 systems for a good accuracy / log rate ratio. Optimal system choice may vary with geographical region. <br> For western europe choose GPS, Galileo and Beidou. <br> M8 (ROM version 2.01) : max 2 GNSS (GPS + GLONASS)<br> M8 (ROM version 3.01) : max 3 GNSS (GPS + GLONASS + GALILEO)<br> M9 : max 4 GNSS (GPS + GLONASS + GALILEO + BEIDOU)<br> M10: max 4 GNSS  (GPS + GLONASS + GALILEO + BEIDOU). <br> Choosing 3 or more systems may limit log rate!</td>\n</tr>\n";
  //logUBX nav-sat message@rate/10
  webpage += "<tr><td>Log nav_sat</td><td>\n<select id='logUBX_nav_sat' name='logUBX_nav_sat'>\n";
  Drop_down_menu(config.logUBX_nav_sat,1,"ON",webpage);
  Drop_down_menu(config.logUBX_nav_sat,0,"OFF",webpage);
  webpage += "</select>\n</td><td>Choose ON to save nav_sat messages in ubx format for optional GPS signal quality evaluation (u-center). Saves 1 nav_sat message for every 10 nav_pvt messages. <br> Requires to set logUBX to ON and log rate < 10 Hz !</td>\n</tr>\n";  
   //Archive_days
  webpage += "<tr>\n<td>Archive days</td><td>\n";
  webpage += "<input size='8' type='number' required name='archive_days' min='0' max='1000' value="+String(config.archive_days)+" step='1'>\n";
  webpage += "</select>\n</td><td>Moves log files older than that into the archive directory to keep the frontpage clean. </td>\n</tr>\n";
  //speed_screen
  webpage += "<tr>\n<td>Speed screen</td><td>\n";
  webpage += "<input size='9' type='text' required name='speed_screen' value="+String(config.speed_screen)+">\n";//input size 9
  webpage += "</select>\n</td><td>Allows to choose what data to show while going faster than stat_speed. Uses two optional top-row items and one big bold number for the main item. <br> 1 = 2s max, 5x10 avg and actual speed, 2 = max alpha, best hour and total distance, 3 = Alfa, 4 = mile, 5 = total distance, 6 = 2s and 10s max, 7 = switching between alfa and 500m, 8 = switching between alfa and 1h, 9 = alfa, 1h, and best 10s run. <br> Choose more than 1 digit to toggle respective screens !</td>\n</tr>\n";  
  //speed_field
  webpage += "<tr>\n<td>Show speed screen</td><td>\n";
  webpage += "<input size='8' type='number' required name='speed_field' min='0' max='99999' value="+String(config.field)+" step='1'>\n";
  webpage += "</select>\n</td><td>Setting to 0 switches off the screen while going faster than stat_speed. Improves battery life !</td>\n</tr>\n";
  //speed_large_font
  #ifndef TTGO_T_DISPLAY
  webpage += "<tr><td>speed_large_font</td><td>\n<select id='speed_large_font' name='speed_large_font'>\n";
  Drop_down_menu(config.speed_large_font,3,"Giant_Font ON",webpage);
  Drop_down_menu(config.speed_large_font,2,"Simon_Font ON",webpage);
  Drop_down_menu(config.speed_large_font,1,"Large_Font ON",webpage);
  Drop_down_menu(config.speed_large_font,0,"Large_Font OFF",webpage);
  webpage += "</select>\n</td><td>speed_large_font: To choose the font sizes of the first line in the speed screen. Choice 0 = small, 1 = medium, 2 = large.</td>\n</tr>\n";  
  //bar_length
  webpage += "<tr>\n<td>bar_length</td><td>\n";
  webpage += "<input size='8' type='number' required name='bar_length' min='100' max='10000' value="+String(config.bar_length)+" step='1'>\n";
  webpage += "</select>\n</td><td>bar_length: Default length = 1852 m for 100% bar (=Nautical mile)</td>\n</tr>\n";
  #endif
  //stat_screen
  webpage += "<tr>\n<td>Statistics screen</td><td>\n";
  webpage += "<input size='9' type='text' required name='stat_screen' value="+String(config.stat_screen)+">\n";//input size 9
  webpage += "</select>\n</td><td>Choose statistic screens. Choose more than one to toggle between screens. <br>1 = first row: 2s max, 5x10 avg, 100m, 250m, 500m and second row: alfa, mile, half hour, hour, distance<br>2 = distance, mile, hour, alfa<br>3 = 100m, 250m, 500m, 2s<br>4 = 100m, 250m, 500m, alfa<br>5 = best 10s runs<br>6 = best 250m runs<br>7 = best 500m runs<br>8 = best alfas</td>\n</tr>\n";  
  //Stat_screens_time
  webpage += "<tr>\n<td>Stat screens toogle time</td><td>\n";
  webpage += "<input size='8' type='number' required name='Stat_screens_time' min='2' max='10' value="+String(config.Stat_screens_time)+" step='1'>\n";
  webpage += "</select>\n</td><td>Sets the duration in seconds to show each stat screen before toggling. </td>\n</tr>\n";
  //Stat_speed
  webpage += "<tr>\n<td>Speed screen speed</td><td>\n";
  webpage += "<input size='8' type='number' required name='stat_speed' min='0' max='10' value="+String(config.stat_speed)+" step='1'>\n";
  webpage += "</select>\n</td><td>Sets the threshold speed (in m/s) to switch from statistic to speed screens. </td>\n</tr>\n";
   //Start_logging_speed
  webpage += "<tr>\n<td>Start logging speed</td><td>\n";
  webpage += "<input size='8' type='number' required name='start_logging_speed' min='0' max='10' value="+String(config.start_logging_speed)+" step='1'>\n";
  webpage += "</select>\n</td><td>Sets the threshold speed(in m/s) to start logging.</td>\n</tr>\n"; 
  //GPIO12_screens
  #ifndef TTGO_T_DISPLAY
  webpage += "<tr>\n<td>GPIO12_screens</td><td>\n";
  webpage += "<input size='8' type='number' required name='GPIO12_screens' min='0' max='1000' value="+String(config.GPIO12_screens_persist)+" step='1'>\n";
  webpage += "</select>\n</td><td>GPIO12_screens choice : Every digit shows the according GPIO_screen after each push. Screen 4 = s10 runs, screen 5 = alfa's.</td>\n</tr>\n";
  //Board_Logo
  webpage += "<tr>\n<td>Board_Logo</td><td>\n<select id='Board_Logo' name='Board_Logo'>";
  Drop_down_menu(config.Board_Logo,0,"No logo",webpage);
  Drop_down_menu(config.Board_Logo,1,"Starboard",webpage);
  Drop_down_menu(config.Board_Logo,2,"Fanatic",webpage);
  Drop_down_menu(config.Board_Logo,3,"JP",webpage);
  Drop_down_menu(config.Board_Logo,4,"Nove Nove",webpage);
  Drop_down_menu(config.Board_Logo,5,"Mistral",webpage);
  Drop_down_menu(config.Board_Logo,6,"Goya",webpage);
  Drop_down_menu(config.Board_Logo,7,"Patrik",webpage);
  Drop_down_menu(config.Board_Logo,8,"Severne",webpage);
  Drop_down_menu(config.Board_Logo,9,"Tabou",webpage);
  Drop_down_menu(config.Board_Logo,10,"F2",webpage);
  Drop_down_menu(config.Board_Logo,11,"Schweighofer",webpage);
  Drop_down_menu(config.Board_Logo,12,"Thommen",webpage);
  Drop_down_menu(config.Board_Logo,13,"Bic",webpage);
  Drop_down_menu(config.Board_Logo,14,"Carbon Art",webpage);
  Drop_down_menu(config.Board_Logo,15,"Future Fly",webpage);
  Drop_down_menu(config.Board_Logo,16,"One Hundred",webpage);
  Drop_down_menu(config.Board_Logo,17,"FMX",webpage);
  Drop_down_menu(config.Board_Logo,18,"Phantom",webpage);
  Drop_down_menu(config.Board_Logo,19,"F4 Foil",webpage);
  webpage += "</select>\n</td><td>Board_Logo :  See the logos on <a href='https://www.seabreeze.com.au/img/photos/windsurfing/19565287.jpg' target='_blank'>this Link</a></td>\n</tr>\n";
  //Sail_Logo Drop down menu
  webpage += "<tr>\n<td>Sail_Logo</td><td>\n<select id='Sail_Logo' name='Sail_Logo'>";
  Drop_down_menu(config.Sail_Logo,0,"No logo",webpage);
  Drop_down_menu(config.Sail_Logo,1,"GA-Sails",webpage);
  Drop_down_menu(config.Sail_Logo,2,"Duotone",webpage);
  Drop_down_menu(config.Sail_Logo,3,"Neil Pryde NP",webpage);
  Drop_down_menu(config.Sail_Logo,4,"Neil Pryde O",webpage);
  Drop_down_menu(config.Sail_Logo,5,"Loft Sails",webpage);
  Drop_down_menu(config.Sail_Logo,6,"Gun",webpage);
  Drop_down_menu(config.Sail_Logo,7,"Point 7",webpage);
  Drop_down_menu(config.Sail_Logo,8,"Simmer",webpage);
  Drop_down_menu(config.Sail_Logo,9,"Naish",webpage);
  Drop_down_menu(config.Sail_Logo,10,"Severne",webpage);
  Drop_down_menu(config.Sail_Logo,11,"S2 Maui",webpage);
  Drop_down_menu(config.Sail_Logo,12,"North Sails",webpage);
  Drop_down_menu(config.Sail_Logo,13,"Challenger Sails",webpage);
  Drop_down_menu(config.Sail_Logo,14,"Phantom",webpage);
  Drop_down_menu(config.Sail_Logo,15,"Patrik",webpage);
  webpage += "</select>\n</td><td>Sail_Logo :  See the logos on <a href='https://www.seabreeze.com.au/img/photos/windsurfing/19565287.jpg' target='_blank'>this Link</a></td>\n</tr>\n";
  //sleep_off_screen
  webpage += "<tr>\n<td>sleep_off_screen</td><td>\n";
  webpage += "<input size='8' type='number' required name='sleep_off_screen' min='0' max='1000' value="+String(config.sleep_off_screen)+" step='1'>\n";
  webpage += "</select>\n</td><td>Choice for switch_off (first digit 0 or 1) and sleep_screen (second digit 0 or 1): </td>\n</tr>\n";
  #endif
  //logTXT
  webpage += "<tr><td>Log TXT</td><td>\n<select id='logTXT' name='logTXT'>\n";
  if(config.logTXT == 1) webpage += "<option value='1' selected>ON</option>\n"; else webpage += "<option value='1'>ON</option>\n";
  if(config.logTXT == 0) webpage += "<option value='0' selected>OFF</option>\n"; else webpage += "<option value='0'>OFF</option>\n";
  webpage += "</select>\n</td><td>Saves a plain text file with errors, status information and session results at shutdown.</td>\n</tr>\n"; 
  //logSBP
  webpage += "<tr><td>Log SBP</td><td>\n<select id='logSBP' name='logSBP'>\n";
  if(config.logSBP == 1) webpage += "<option value='1' selected>ON</option>\n"; else webpage += "<option value='1'>ON</option>\n";
  if(config.logSBP == 0) webpage += "<option value='0' selected>OFF</option>\n"; else webpage += "<option value='0'>OFF</option>\n";
  webpage += "</select>\n</td><td>Saves a logfile in sbp format including correction data. This is the original locosys navilink file standard, approved for upload to GP3S and use in competitions. Reduces filesize by ~70% vs ubx.</td>\n</tr>\n";  
  //logUBX
  webpage += "<tr><td>Log UBX</td><td>\n<select id='logUBX' name='logUBX'>\n";
  if(config.logUBX == 1) webpage += "<option value='1' selected>ON</option>\n"; else webpage += "<option value='1'>ON</option>\n";
  if(config.logUBX == 0) webpage += "<option value='0' selected>OFF</option>\n"; else webpage += "<option value='0'>OFF</option>\n";
  webpage += "</select>\n</td><td>Saves a logfile in ubx format. This is the u-blox proprietary file format, approved for upload to GP3S.</td>\n</tr>\n";  
  //logGPY  
  webpage += "<tr><td>Log GPY</td><td>\n<select id='logGPY' name='logGPY'>\n";
  if(config.logGPY == 1) webpage += "<option value='1' selected>ON</option>\n"; else webpage += "<option value='1'>ON</option>\n";
  if(config.logGPY == 0) webpage += "<option value='0' selected>OFF</option>\n"; else webpage += "<option value='0'>OFF</option>\n";
  webpage += "</select>\n</td><td>Saves a logfile in the new open source gpy format, approved for upload to GP3S. </td>\n</tr>\n";  
  //logGPX  
  webpage += "<tr><td>Log GPX</td><td>\n<select id='logGPX' name='logGPX'>\n";
  if(config.logGPX == 1) webpage += "<option value='1' selected>ON</option>\n"; else webpage += "<option value='1'>ON</option>\n";
  if(config.logGPX == 0) webpage += "<option value='0' selected>OFF</option>\n"; else webpage += "<option value='0'>OFF</option>\n";
  webpage += "</select>\n</td><td>Saves a logfile in gpx data exchange format at 1Hz. Useful for video overlay or other individual purposes, but NOT approved for GP3S upload or contest use due to consistency issues. </td>\n</tr>\n";  
  //timezone
  webpage += "<tr>\n<td>Timezone</td><td>\n<select id='timezone' name='timezone' type='number'>\n"; 
  Drop_down_menu(config.timezone,-11.0,"-11 (Pacific/Samoa)",webpage);
  Drop_down_menu(config.timezone,-10.0,"-10 (US/Hawaii)",webpage);
  Drop_down_menu(config.timezone,-9.5,"-9:30 (Pacific/Marquesas)",webpage);
  Drop_down_menu(config.timezone,-9.0,"-9 (US/Alaska)",webpage);
  Drop_down_menu(config.timezone,-8.0,"-8 (US/Pacific)",webpage);
  Drop_down_menu(config.timezone,-7.0,"-7 (US/Montaain)",webpage); 
  Drop_down_menu(config.timezone,-6.0,"-6 (US/Central)",webpage);
  Drop_down_menu(config.timezone,-5.0,"-5 (US/Eastern)",webpage); 
  Drop_down_menu(config.timezone,-4.0,"-4 (Canada/Atlantic)",webpage); 
  Drop_down_menu(config.timezone,-3.5,"-3:30 (Canada/Newfoundland)",webpage); 
  Drop_down_menu(config.timezone,-3.0,"-3 (Brazil/East)",webpage); 
  Drop_down_menu(config.timezone,-2.0,"-2 (Brazil/DeNoronha)",webpage);
  Drop_down_menu(config.timezone,-1.0,"-1 (Atlantic/CapVerde)",webpage); 
  Drop_down_menu(config.timezone,0.0,"GMT(Europe/London)",webpage);
  Drop_down_menu(config.timezone,1.0,"CET(Europe/Brussels)",webpage);
  Drop_down_menu(config.timezone,2.0,"CET+1(Europe/Athens)",webpage);
  Drop_down_menu(config.timezone,3.0,"+3 (Turkey)",webpage);  
  Drop_down_menu(config.timezone,3.5,"+3:30 (Iran)",webpage);
  Drop_down_menu(config.timezone,4.0,"+4 (Indian/Mauritius)",webpage);
  Drop_down_menu(config.timezone,5.0,"+5 (Indian/Maldives)",webpage);
  Drop_down_menu(config.timezone,5.5,"+5:30 (Asia/Calcutta)",webpage);
  Drop_down_menu(config.timezone,5.75,"+5:45 (Asia/Katmandu)",webpage);
  Drop_down_menu(config.timezone,6.0,"+6 (Asia/Omsk)",webpage);
  Drop_down_menu(config.timezone,6.5,"+6:30 (Asia/Rangoon)",webpage);
  Drop_down_menu(config.timezone,7.0,"+7 (Asia/Bangkok)",webpage);
  Drop_down_menu(config.timezone,8.0,"+8 (Australia/Perth)",webpage);
  Drop_down_menu(config.timezone,8.75,"+8:45 (Australia/Eucla)",webpage);
  Drop_down_menu(config.timezone,9.0,"+9 (Japan)",webpage); 
  Drop_down_menu(config.timezone,9.5,"+9:30 (Australia/South)",webpage);
  Drop_down_menu(config.timezone,10.0,"+10 (Australia/Sydney)",webpage);
  Drop_down_menu(config.timezone,10.5,"+10:30 (Australia/LHI)",webpage);
  Drop_down_menu(config.timezone,11.0,"+11 (Pacific/Noumea)",webpage);
  Drop_down_menu(config.timezone,12.0,"+12 (NZ)",webpage);
  Drop_down_menu(config.timezone,12.75,"+12:45 (Pacific/Chatham)",webpage);
  Drop_down_menu(config.timezone,13.0,"+13 (Pacific/Fakaofo)",webpage);
  Drop_down_menu(config.timezone,14.0,"+14 (Pacific/Kiritimati)",webpage);    
  webpage += "</select>\n</td><td>Sets local time offset from UTC, can be fractional / negative ! <a href='https://en.wikipedia.org/wiki/List_of_UTC_offsets' target='_blank'>this Link</a></td>\n</tr>\n";
  //timezone daylight saving
  webpage += "<tr><td>Daylight Saving</td><td>\n<select id='timezone_DST' name='timezone_DST'>\n";
  if(config.timezone_DST == 1) webpage += "<option value='1' selected>ON</option>\n"; else webpage += "<option value='1'>ON</option>\n";
  if(config.timezone_DST == 0) webpage += "<option value='0' selected>OFF</option>\n"; else webpage += "<option value='0'>OFF</option>\n";
  webpage += "</select>\n</td><td>Set ON for optional automatic switching to daylight saving time </td>\n</tr>\n";  
  //filenaming  
  webpage += "<tr><td>Filename sequence</td><td>\n<select id='file_date_time' name='file_date_time'>\n";
  Drop_down_menu(config.file_date_time,0,"name_MAC_index",webpage);
  Drop_down_menu(config.file_date_time,1,"name_date_time",webpage);   
  Drop_down_menu(config.file_date_time,2,"date_time_name",webpage);
  Drop_down_menu(config.file_date_time,3,"name_date_time_MAC",webpage);
  webpage += "</select>\n</td><td>Choose the desired order of filename elements. Set to 1 for standard filename sequence: name_date_time.</td>\n</tr>\n"; 
  //UBXfile
  webpage += "<tr>\n<td>Your name</td><td>\n";
  webpage += "<input size='10' type='text' required name='UBXfile' value="+String(config.UBXfile)+">\n";
  webpage += "</select>\n</td><td>Choose an individual name for your logs, maximum is 10 characters! Other filename elements will be added as set in filename sequence.</td>\n</tr>\n";
  //Sleep_info
  String Sleep_info="\"" + String(config.Sleep_info) + "\"";
  webpage += "<tr>\n<td>Sleep info</td><td>\n";
  webpage += "<input size='21' type='text' required name='Sleep_info' value="+Sleep_info+">\n";//size 20 -> 21
  webpage += "</select>\n</td><td>Text to display during sleep on e-paper hardware. Maximun 21 characters. </td>\n</tr>\n";
  //reboot the esp
  webpage += "<tr><td>Save and reboot</td><td>\n<select id='reboot' name='reboot'>\n";
  webpage += "<option value='yes' selected>yes</option>\n";
  webpage += "<option value='no'>no</option>\n";
  webpage += "</select>\n</td><td>Set to yes for reboot after config changes. Required for new config to take effect.</td>\n</tr>\n";  
}

 const char html_config_footer[] PROGMEM = R"=====(
     </table>
    <button class="button" type="submit">Submit</button>
</FORM>
  )=====";
