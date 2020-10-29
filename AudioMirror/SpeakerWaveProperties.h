#pragma once

#include "Globals.h"
// NOTE(will): These "MAX_CHANNELS" values do not seem to make a difference
// We are able to declare surround sound device formats without them and
// applications (Audacity) are able to open the device in multichannel
// even though the following values are all 2 (which should just be stereo)
// QUESTION: What is the point of MAX_CHANNELS?
#define SPEAKER_DEVICE_MAX_CHANNELS                 2       // Max Channels.

#define SPEAKER_MAX_INPUT_SYSTEM_STREAMS            1
#define SPEAKER_MAX_INPUT_OFFLOAD_STREAMS           0
#define SPEAKER_MAX_OUTPUT_LOOPBACK_STREAMS         MAX_OUTPUT_LOOPBACK_STREAMS

#define SPEAKER_HOST_MAX_CHANNELS                   2       // Max Channels.
#define SPEAKER_HOST_MIN_BITS_PER_SAMPLE            16      // Min Bits Per Sample
#define SPEAKER_HOST_MAX_BITS_PER_SAMPLE            16      // Max Bits Per Sample
#define SPEAKER_HOST_MIN_SAMPLE_RATE                44100   // Min Sample Rate
#define SPEAKER_HOST_MAX_SAMPLE_RATE                44100   // Max Sample Rate

#define SPEAKER_OFFLOAD_MAX_CHANNELS                2       // Max Channels.
#define SPEAKER_OFFLOAD_MIN_BITS_PER_SAMPLE         16      // Min Bits Per Sample
#define SPEAKER_OFFLOAD_MAX_BITS_PER_SAMPLE         16      // Max Bits Per Sample
#define SPEAKER_OFFLOAD_MIN_SAMPLE_RATE             44100   // Min Sample Rate
#define SPEAKER_OFFLOAD_MAX_SAMPLE_RATE             44100   // Max Sample Rate

// NOTE(will): the following is very finicky and I have yet to find any
// documentation that explains the quirkiness.
// For example, I have 7POINT1_SURROUND and 5POINT1 declared and the
// resultant driver exposes both configurations. I can also declare 5POINT1
// by itself and it will work. However, 7POINT1_SURROUND by itself does
// not (driver will be incomplete). The same behavior was observed with QUAD.
// Another issue is that 5POINT1_SURROUND doesn't work.
// QUESTIONS: Why does this API suck? How do we get 7POINT1_SURROUND by itself?
static
KSDATAFORMAT_WAVEFORMATEXTENSIBLE SpeakerHostPinSupportedDeviceFormats[] =
{
	{
		{
			sizeof(KSDATAFORMAT_WAVEFORMATEXTENSIBLE),
			0,
			0,
			0,
			STATICGUIDOF(KSDATAFORMAT_TYPE_AUDIO),
			STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM),
			STATICGUIDOF(KSDATAFORMAT_SPECIFIER_WAVEFORMATEX)
		},
		{
			{
				WAVE_FORMAT_EXTENSIBLE,
				6,			// number of channels
				44100,		// sample rate
				6*2*44100,	// channels * bytes * samples
				6*2,		// channels * bytes
				16,			// bit depth (actually, container size - real bit depth below)
				sizeof(WAVEFORMATEXTENSIBLE) - sizeof(WAVEFORMATEX)
			},
			16, // bit depth
			KSAUDIO_SPEAKER_5POINT1,
			STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM)
		}
	},
	{
		{
			sizeof(KSDATAFORMAT_WAVEFORMATEXTENSIBLE),
			0,
			0,
			0,
			STATICGUIDOF(KSDATAFORMAT_TYPE_AUDIO),
			STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM),
			STATICGUIDOF(KSDATAFORMAT_SPECIFIER_WAVEFORMATEX)
		},
		{
			{
				WAVE_FORMAT_EXTENSIBLE,
				8,			// number of channels
				44100,		// sample rate
				8*2*44100,	// channels * bytes * samples
				8*2,		// channels * bytes
				16,			// bit depth (actually, container size - real bit depth below)
				sizeof(WAVEFORMATEXTENSIBLE) - sizeof(WAVEFORMATEX)
			},
			16, // bit depth
			KSAUDIO_SPEAKER_7POINT1_SURROUND,
			STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM)
		}
	},
	// NOTE(will): Other working configs that I have found
	//{
	//	{
	//		sizeof(KSDATAFORMAT_WAVEFORMATEXTENSIBLE),
	//		0,
	//		0,
	//		0,
	//		STATICGUIDOF(KSDATAFORMAT_TYPE_AUDIO),
	//		STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM),
	//		STATICGUIDOF(KSDATAFORMAT_SPECIFIER_WAVEFORMATEX)
	//	},
	//	{
	//		{
	//			WAVE_FORMAT_EXTENSIBLE,
	//			2,			// number of channels
	//			44100,		// sample rate
	//			2*2*44100,	// channels * bytes * samples
	//			2*2,		// channels * bytes
	//			16,			// bit depth (actually, container size - real bit depth below)
	//			sizeof(WAVEFORMATEXTENSIBLE) - sizeof(WAVEFORMATEX)
	//		},
	//		16, // bit depth
	//		KSAUDIO_SPEAKER_STEREO,
	//		STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM)
	//	}
	//},
	//{
	//	{
	//		sizeof(KSDATAFORMAT_WAVEFORMATEXTENSIBLE),
	//		0,
	//		0,
	//		0,
	//		STATICGUIDOF(KSDATAFORMAT_TYPE_AUDIO),
	//		STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM),
	//		STATICGUIDOF(KSDATAFORMAT_SPECIFIER_WAVEFORMATEX)
	//	},
	//	{
	//		{
	//			WAVE_FORMAT_EXTENSIBLE,
	//			4,			// number of channels
	//			44100,		// sample rate
	//			4*2*44100,	// channels * bytes * samples
	//			4*2,		// channels * bytes
	//			16,			// bit depth (actually, container size - real bit depth below)
	//			sizeof(WAVEFORMATEXTENSIBLE) - sizeof(WAVEFORMATEX)
	//		},
	//		16, // bit depth
	//		KSAUDIO_SPEAKER_QUAD,
	//		STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM)
	//	}
	//},
	//{
	//	{
	//		sizeof(KSDATAFORMAT_WAVEFORMATEXTENSIBLE),
	//		0,
	//		0,
	//		0,
	//		STATICGUIDOF(KSDATAFORMAT_TYPE_AUDIO),
	//		STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM),
	//		STATICGUIDOF(KSDATAFORMAT_SPECIFIER_WAVEFORMATEX)
	//	},
	//	{
	//		{
	//			WAVE_FORMAT_EXTENSIBLE,
	//			4,			// number of channels
	//			44100,		// sample rate
	//			4*2*44100,	// channels * bytes * samples
	//			4*2,		// channels * bytes
	//			16,			// bit depth (actually, container size - real bit depth below)
	//			sizeof(WAVEFORMATEXTENSIBLE) - sizeof(WAVEFORMATEX)
	//		},
	//		16, // bit depth
	//		KSAUDIO_SPEAKER_SURROUND,
	//		STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM)
	//	}
	//},
};

static
MODE_AND_DEFAULT_FORMAT SpeakerHostPinSupportedDeviceModes[] =
{
	{
		STATIC_AUDIO_SIGNALPROCESSINGMODE_DEFAULT,
		&SpeakerHostPinSupportedDeviceFormats[0].DataFormat // 48KHz
	},
};

static PIN_DEVICE_FORMATS_AND_MODES SpeakerPinDeviceFormatsAndModes[] =
{
	{
		PinType::SystemRenderPin,
		SpeakerHostPinSupportedDeviceFormats,
		SIZEOF_ARRAY(SpeakerHostPinSupportedDeviceFormats),
		SpeakerHostPinSupportedDeviceModes,
		SIZEOF_ARRAY(SpeakerHostPinSupportedDeviceModes)
	},
	{
		PinType::BridgePin,
		NULL,
		0,
		NULL,
		0
	},
};

static KSDATARANGE_AUDIO SpeakerPinDataRangesStream[] =
{
	{ // 0
		{
			sizeof(KSDATARANGE_AUDIO),
			KSDATARANGE_ATTRIBUTES,         // An attributes list follows this data range
			0,
			0,
			STATICGUIDOF(KSDATAFORMAT_TYPE_AUDIO),
			STATICGUIDOF(KSDATAFORMAT_SUBTYPE_PCM),
			STATICGUIDOF(KSDATAFORMAT_SPECIFIER_WAVEFORMATEX)
		},
		SPEAKER_HOST_MAX_CHANNELS,
		SPEAKER_HOST_MIN_BITS_PER_SAMPLE,
		SPEAKER_HOST_MAX_BITS_PER_SAMPLE,
		SPEAKER_HOST_MIN_SAMPLE_RATE,
		SPEAKER_HOST_MAX_SAMPLE_RATE
	},
};

static
PKSDATARANGE SpeakerPinDataRangePointersStream[] =
{
	PKSDATARANGE(&SpeakerPinDataRangesStream[0]),
	PKSDATARANGE(&PinDataRangeAttributeList),
};

static
KSDATARANGE SpeakerPinDataRangesBridge[] =
{
	{
		sizeof(KSDATARANGE),
		0,
		0,
		0,
		STATICGUIDOF(KSDATAFORMAT_TYPE_AUDIO),
		STATICGUIDOF(KSDATAFORMAT_SUBTYPE_ANALOG),
		STATICGUIDOF(KSDATAFORMAT_SPECIFIER_NONE)
	}
};

static
PKSDATARANGE SpeakerPinDataRangePointersBridge[] =
{
	&SpeakerPinDataRangesBridge[0]
};

static PCPIN_DESCRIPTOR SpeakerWaveMiniportPins[] =
{
	// Wave Out Streaming Pin (Renderer) KSPIN_WAVE_RENDER_SINK_SYSTEM
	{
		SPEAKER_MAX_INPUT_SYSTEM_STREAMS,
		SPEAKER_MAX_INPUT_SYSTEM_STREAMS,
		0,
		NULL,        // AutomationTable
		{
			0,
			NULL,
			0,
			NULL,
			SIZEOF_ARRAY(SpeakerPinDataRangePointersStream),
			SpeakerPinDataRangePointersStream,
			KSPIN_DATAFLOW_IN,
			KSPIN_COMMUNICATION_SINK,
			&KSNODETYPE_SPEAKER,
			NULL,
			0
		}
	},
	// Wave Out Bridge Pin (Renderer) KSPIN_WAVE_RENDER_SOURCE
	{
		0,
		0,
		0,
		NULL,
		{
			0,
			NULL,
			0,
			NULL,
			SIZEOF_ARRAY(SpeakerPinDataRangePointersBridge),
			SpeakerPinDataRangePointersBridge,
			KSPIN_DATAFLOW_OUT,
			KSPIN_COMMUNICATION_NONE,
			&KSNODETYPE_SPEAKER,
			NULL,
			0
		}
	},
};

static PCPROPERTY_ITEM PropertiesSpeakerWaveFilter[] =
{
	{
		&KSPROPSETID_Pin,
		KSPROPERTY_PIN_PROPOSEDATAFORMAT,
		KSPROPERTY_TYPE_SET | KSPROPERTY_TYPE_BASICSUPPORT,
		MiniportWaveRT::PropertyHandler_WaveFilter
	},
	{
		&KSPROPSETID_Pin,
		KSPROPERTY_PIN_PROPOSEDATAFORMAT2,
		KSPROPERTY_TYPE_GET | KSPROPERTY_TYPE_BASICSUPPORT,
		MiniportWaveRT::PropertyHandler_WaveFilter
	},
};
DEFINE_PCAUTOMATION_TABLE_PROP(AutomationSpeakerWaveFilter, PropertiesSpeakerWaveFilter);

//=============================================================================
//
//                   ----------------------------      
//                   |                          |      
//  System Pin   0-->|                          |
//                   |      				    |      
//  |											|--> 1 KSPIN_WAVE_RENDER_SOURCE
//                   |                          |      
//                   ----------------------------       
static PCCONNECTION_DESCRIPTOR SpeakerWaveMiniportConnections[] =
{
	{ PCFILTER_NODE,						(int)WaveRenderPins::SINK_SYSTEM,   PCFILTER_NODE,						(int)WaveRenderPins::SOURCE },
};

static PCFILTER_DESCRIPTOR SpeakerWaveMiniportFilterDescriptor =
{
	0,                                              // Version
	&AutomationSpeakerWaveFilter,                   // AutomationTable
	sizeof(PCPIN_DESCRIPTOR),                       // PinSize
	SIZEOF_ARRAY(SpeakerWaveMiniportPins),          // PinCount
	SpeakerWaveMiniportPins,                        // Pins
	sizeof(PCNODE_DESCRIPTOR),                      // NodeSize
	0,												// NodeCount
	NULL,											// Nodes
	SIZEOF_ARRAY(SpeakerWaveMiniportConnections),   // ConnectionCount
	SpeakerWaveMiniportConnections,                 // Connections
	0,                                              // CategoryCount
	NULL                                            // Categories  - use defaults (audio, render, capture)
};