from temboo.Library.Google.Calendar import GetEvent
from temboo.core.session import TembooSession
import time
import datetime
import json

# Instantiate the Choreo, using a previously instantiated TembooSession object, eg:
session = TembooSession('davidptracy', 'NudgePoC', '866b16949a1c452d94903061501ccc7f')
getEventChoreo = GetEvent(session)

# Get an InputSet object for the choreo
getEventInputs = getEventChoreo.new_input_set()

# Set credential to use for execution
getEventInputs.set_credential('NudgePoC')

# Set inputs
getEventInputs.set_CalendarID("ejotm9082g5v8m4b5393vac7o4@group.calendar.google.com")
getEventInputs.set_EventID("eqmrclm7r9q7ovr1h1eeth6h0o")

# Execute choreo
getEventResults = getEventChoreo.execute_with_results(getEventInputs)

results = getEventResults.get_Response()

js = json.loads(results)
ourResults = js['start']['dateTime']

  #This simple script will take an EVENT time in ISO8601 and return the time in seconds until that event
ISOtime = ourResults  #time of event in ISO8601  
 
#strip the timezone because time.mktime already assumes local time
ISOtime = ISOtime.replace(ISOtime[-6:],"")
#convert ISOtime to UNIX timecode
UNIXtime = time.mktime(time.strptime(ISOtime,'%Y-%m-%dT%H:%M:%S'))
#current Unix Timestamp as an INT
timestamp = long(time.time())    
#subtract Unix Timestamp from the event unix time to get time until event
timeLeft = long(UNIXtime-timestamp)
print timeLeft