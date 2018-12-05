
#include <stdlib.h>
#include <string.h>
#include "WAVheader.h"
#include <math.h>
#include <stdio.h>
#include "common.h"
#include "fixed_point_math.h"
/**
 *
 * Swaps upper and lower half of audio samples. Mixing an inverted sample on top of
 * the original with a slight delay can produce effects that sound like resonance.
 * Creating a stereo sample from a mono source, with one channel inverted produces wide-stereo sounds.
 *
 */

void audio_invert_init()
{
	data.degree = FRACT_NUM(0.0); 
	data.gain = FRACT_NUM(-1.0);
}
/*
void gst_audio_invert_transform()
{	
	DSPfract *leftOutput1=sampleBuffer[0];
	DSPfract *rightOutput1=sampleBuffer[2];
	if(data.whichChannelInvert==2)
	{	 
		for (DSPint i = 0; i < BLOCK_SIZE; i++) 
		{
		val = *leftOutput1 * dry - (*leftOutput1) * data.degree;
		*leftOutput1 = val * data.gain;
		leftOutput1++;
		}
	}
	else if(data.whichChannelInvert==0)
	{
		for (DSPint i = 0; i < BLOCK_SIZE; i++) 
		{
		val = *rightOutput1 * dry - (*rightOutput1) * data.degree;
		*rightOutput1 = val * data.gain;
		rightOutput1++;
		}
	}
}
*/

void processing()
{

	switch(outputMode)
	{
	case MODE_3_2_0:
			leftInput=tempBuffer[0];
			rightInput=tempBuffer[1];
			centralInput=tempBuffer[0];	
			lsInput=tempBuffer[0];	
			rsInput=tempBuffer[1];	

			leftOutput=sampleBuffer[0];
			rightOutput=sampleBuffer[2];
			centralOutput=sampleBuffer[1];	
			lsOutput=sampleBuffer[3];	
			rsOutput=sampleBuffer[4];
		switch(mode_switch)
		{
		case MODE1:
			for(DSPint j=0; j<BLOCK_SIZE; j++)
			{
				*leftOutput=*leftInput*input_gain ;	//l
				*leftOutput=*leftOutput*FRACT_NUM(-1.0);
				*leftOutput=*leftOutput<<1;
				*centralOutput=*centralInput*input_gain; 
				*centralOutput=*centralOutput*INPUT_MODE1_C;	//c
				*centralOutput=*centralOutput<<1;
				*centralOutput=*centralOutput<<1;
				*lsOutput=*lsInput*input_gain;
				*lsOutput=*lsOutput*INPUT_MODE1_LS;	//ls
				*lsOutput=*lsOutput<<1;

				*rightOutput=*rightInput*input_gain;	//r
				*rightOutput=*rightOutput*FRACT_NUM(-1.0);
				*rightOutput=*rightOutput<<1;
				*rsOutput=*rsInput*input_gain * -1;	//rs
				*rsOutput=*rsOutput<<1;

				leftOutput++;
				rightOutput++;
				rsOutput++;
				centralOutput++;
				lsOutput++;

				centralInput++;
				lsInput++;
				rsInput++;
				rightInput++;
				leftInput++;	
			}
			//data.whichChannelInvert=2;
			//gst_audio_invert_transform(); //R inv
			//data.whichChannelInvert=0;
			//gst_audio_invert_transform(); //L inv
		
			break;


		case MODE0:
			for(DSPint j=0; j<BLOCK_SIZE; j++)
			{
				*leftOutput=*leftInput*input_gain ;	//l
				*leftOutput=*leftOutput*FRACT_NUM(-1.0);
				*leftOutput=*leftOutput<<1;
				*centralOutput=*centralInput*input_gain; 
				*centralOutput=*centralOutput*INPUT_MODE0_C;	//c
				*centralOutput=*centralOutput<<1;
				*centralOutput=*centralOutput<<1;
				*lsOutput=*lsInput*input_gain;
				*lsOutput=*lsOutput*INPUT_MODE0_LS;	//ls
				*lsOutput=*lsOutput<<1;

				*rightOutput=*rightInput*input_gain;	//r
				*rightOutput=*rightOutput*FRACT_NUM(-1.0);
				*rightOutput=*rightOutput<<1;
				*rsOutput=*rsInput*input_gain * -1;	//rs
				*rsOutput=*rsOutput<<1;

				leftOutput++;
				rightOutput++;
				rsOutput++;
				centralOutput++;
				lsOutput++;

				centralInput++;
				lsInput++;
				rsInput++;
				rightInput++;
				leftInput++;	
			}

				//data.whichChannelInvert=2;
				//gst_audio_invert_transform(); //R inv
				//data.whichChannelInvert=0;
				//gst_audio_invert_transform(); //L inv	
			break;
		}
		
		break;

		case MODE_2_0_0:
			leftInput=tempBuffer[0];
			rightInput=tempBuffer[1];

			leftOutput=sampleBuffer[0];
			rightOutput=sampleBuffer[2];
		switch(mode_switch)
		{
			case MODE1:
				for(DSPint j=0; j<BLOCK_SIZE; j++)
				{
				*leftOutput=*leftInput*input_gain ;	//l
				*leftOutput=*leftOutput*FRACT_NUM(-1.0);
				*leftOutput=*leftOutput<<1;
			
				*rightOutput=*rightInput*input_gain;	//r
				*rightOutput=*rightOutput*FRACT_NUM(-1.0);
				*rightOutput=*rightOutput<<1;

				leftOutput++;
				rightOutput++;
				
				rightInput++;
				leftInput++;	
			}
				//data.whichChannelInvert=2;
				//gst_audio_invert_transform(); //R inv
				//data.whichChannelInvert=0;
				//gst_audio_invert_transform(); //L inv	
			break;


			case MODE0:
				for(DSPint j=0; j<BLOCK_SIZE; j++)
				{
				*leftOutput=*leftInput*input_gain ;	//l
				*leftOutput=*leftOutput*FRACT_NUM(-1.0);
				*leftOutput=*leftOutput<<1;
			
				*rightOutput=*rightInput*input_gain;	//r
				*rightOutput=*rightOutput*FRACT_NUM(-1.0);
				*rightOutput=*rightOutput<<1;

				leftOutput++;
				rightOutput++;
				
				rightInput++;
				leftInput++;	
			}
				//data.whichChannelInvert=2;
				//gst_audio_invert_transform(); //R inv
				//data.whichChannelInvert=0;
				//gst_audio_invert_transform(); //L inv	
			break;
			}
		
		break;

		case MODE_2_2_0:
			leftInput=tempBuffer[0];
			rightInput=tempBuffer[1];
			lsInput=tempBuffer[0];	
			rsInput=tempBuffer[1];	

			leftOutput=sampleBuffer[0];
			rightOutput=sampleBuffer[2];
			lsOutput=sampleBuffer[3];	
			rsOutput=sampleBuffer[4];
		switch(mode_switch)
		{
		case MODE1:
			for(DSPint j=0; j<BLOCK_SIZE; j++)
			{
				*leftOutput=*leftInput*input_gain ;	//l
				*leftOutput=*leftOutput*FRACT_NUM(-1.0);
				*leftOutput=*leftOutput<<1;
				*lsOutput=*lsInput*input_gain;
				*lsOutput=*lsOutput*INPUT_MODE1_LS;	//ls
				*lsOutput=*lsOutput<<1;

				*rightOutput=*rightInput*input_gain;	//r
				*rightOutput=*rightOutput*FRACT_NUM(-1.0);
				*rightOutput=*rightOutput<<1;
				*rsOutput=*rsInput*input_gain * -1;	//rs
				*rsOutput=*rsOutput<<1;

				leftOutput++;
				rightOutput++;
				rsOutput++;
				lsOutput++;

				lsInput++;
				rsInput++;
				rightInput++;
				leftInput++;
			}
				//data.whichChannelInvert=2;
				//gst_audio_invert_transform(); //R inv
				//data.whichChannelInvert=0;
				//gst_audio_invert_transform(); //L inv		
			break;


		case MODE0:
			for(DSPint j=0; j<BLOCK_SIZE; j++)
			{
				*leftOutput=*leftInput*input_gain ;	//l
				*leftOutput=*leftOutput*FRACT_NUM(-1.0);
				*leftOutput=*leftOutput<<1;
				*lsOutput=*lsInput*input_gain;
				*lsOutput=*lsOutput*INPUT_MODE0_LS;	//ls
				*lsOutput=*lsOutput<<1;

				*rightOutput=*rightInput*input_gain;	//r
				*rightOutput=*rightOutput*FRACT_NUM(-1.0);
				*rightOutput=*rightOutput<<1;
				*rsOutput=*rsInput*input_gain * -1;	//rs
				*rsOutput=*rsOutput<<1;

				leftOutput++;
				rightOutput++;
				rsOutput++;
				lsOutput++;

				lsInput++;
				rsInput++;
				rightInput++;
				leftInput++;
			}
			//data.whichChannelInvert=2;
				//gst_audio_invert_transform(); //R inv
				//data.whichChannelInvert=0;
				//gst_audio_invert_transform(); //L inv	
			break;
		}
		
		break;

		case MODE_3_0_0:
			leftInput=tempBuffer[0];
			rightInput=tempBuffer[1];
			centralInput=tempBuffer[0];	
	
			leftOutput=sampleBuffer[0];
			rightOutput=sampleBuffer[2];
			centralOutput=sampleBuffer[1];	
		switch(mode_switch)
		{
		case MODE1:
			for(DSPint j=0; j<BLOCK_SIZE; j++)
			{
				*leftOutput=*leftInput*input_gain ;	//l
				*leftOutput=*leftOutput*FRACT_NUM(-1.0);
				*leftOutput=*leftOutput<<1;
				*centralOutput=*centralInput*input_gain; 
				*centralOutput=*centralOutput*INPUT_MODE1_C;	//c
				*centralOutput=*centralOutput<<1;
				*centralOutput=*centralOutput<<1;

				*rightOutput=*rightInput*input_gain;	//r
				*rightOutput=*rightOutput*FRACT_NUM(-1.0);
				*rightOutput=*rightOutput<<1;

				leftOutput++;
				rightOutput++;
				centralOutput++;

				centralInput++;
				rightInput++;
				leftInput++;	
			}
				//data.whichChannelInvert=2;
				//gst_audio_invert_transform(); //R inv
				//data.whichChannelInvert=0;
				//gst_audio_invert_transform(); //L inv	
			break;


		case MODE0:
			for(DSPint j=0; j<BLOCK_SIZE; j++)
			{
				*leftOutput=*leftInput*input_gain ;	//l
				*leftOutput=*leftOutput*FRACT_NUM(-1.0);
				*leftOutput=*leftOutput<<1;
				*centralOutput=*centralInput*input_gain; 
				*centralOutput=*centralOutput*INPUT_MODE0_C;	//c
				*centralOutput=*centralOutput<<1;
				*centralOutput=*centralOutput<<1;

				*rightOutput=*rightInput*input_gain;	//r
				*rightOutput=*rightOutput*FRACT_NUM(-1.0);
				*rightOutput=*rightOutput<<1;

				leftOutput++;
				rightOutput++;
				centralOutput++;

				centralInput++;
				rightInput++;
				leftInput++;	
			}
				//data.whichChannelInvert=2;
				//gst_audio_invert_transform(); //R inv
				//data.whichChannelInvert=0;
				//gst_audio_invert_transform(); //L inv	
			break;
		}
		
		break;

	}
}

DSPfract dBToinput_gain()
{
  input_gain=input_gain/(DSPfract)20.0;
  return FRACT_NUM(pow(10.0f, input_gain));
}

DSPint main(DSPint argc, char* argv[])
{
	FILE *wav_in=NULL;
	FILE *wav_out=NULL;
	char WavInputName[256];
	char WavOutputName[256];
	
	WAV_HEADER inputWAVhdr,outputWAVhdr;	

	// Init channel buffers
		// Init channel buffers
	for(DSPint i=0; i<MAX_NUM_CHANNEL; i++)
	{
		for(DSPint j=0; j<BLOCK_SIZE; j++)
		{
			sampleBuffer[i][j] = FRACT_NUM(0.0);
			tempBuffer[i][j] = FRACT_NUM(0.0);
		}
	}
	// Open input and output wav files
	//-------------------------------------------------
	strcpy(WavInputName,argv[1]);
	wav_in = OpenWavFileForRead (WavInputName,"rb");
	strcpy(WavOutputName,argv[2]);
	wav_out = OpenWavFileForRead (WavOutputName,"wb");

	if(argc==2){
		printf("uzimam default vrednosti!\n");
	}
	else if(argc!=7 && argc!=2)
	{
		printf("nema dovoljno argumenata!\n");
		return -1;
	}
	else
	{

	//enable switch
	enable=atoi(argv[3]);
	printf("enabled(1) or not(0) %d\n",enable);
	
	//decibel input
	//strcpy(decibels,argv[4]);
	//input_gain=strtol(decibels,&pEnd,10);
	//input_gain=dBToinput_gain(); //konvertovanje input_gain u decimalnu reprezentaciju
	//ovde mu direktno unosim u decimalnom obliku
	//printf("%f dB\n",input_gain.toLong());

	//mode selection
	DSPint mode=atoi(argv[5]);
	switch(mode)
	{
	case 0:
		printf("MODE0!\n");
		mode_switch=MODE0;
		break;
	case 1:
		printf("MODE1!\n");
		mode_switch=MODE1;
		break;
	default:
		printf("MODE1!\n");
		mode_switch=MODE1;
		break;
	}


	DSPint outputMode1=atoi(argv[6]);
	DSPint outputMode2=atoi(argv[6]+2);
	if(outputMode1==2 && outputMode2==2)
	{
		printf("2_2_0!\n");
		outputMode=MODE_2_2_0;
	}
	else if(outputMode1==2 && outputMode2==0)
	{
		printf("2_0_0!\n");
		outputMode=MODE_2_0_0;
	}
	else if(outputMode1==3 && outputMode2==0)
	{
		printf("3_0_0!\n");
		outputMode=MODE_3_0_0;
	}
	else if(outputMode1==3 && outputMode2==2)
	{
		printf("3_2_0!\n");
		outputMode=MODE_3_2_0;
	}
	else
	{
		printf("default 2_2_0!\n");
		outputMode=MODE_2_2_0;
	}
	}

	/*promeniti mu da ocitava mode kao argument,i da prosledi dole u processingu*/
	//-------------------------------------------------

	// Read input wav header
	//-------------------------------------------------
	ReadWavHeader(wav_in,inputWAVhdr);
	//-------------------------------------------------
	
	// Set up output WAV header
	//-------------------------------------------------	
	outputWAVhdr = inputWAVhdr;
	outputWAVhdr.fmt.NumChannels = NUM_CHANNEL_OUT; // change number of channels

	DSPint oneChannelSubChunk2Size = inputWAVhdr.data.SubChunk2Size/inputWAVhdr.fmt.NumChannels;
	DSPint oneChannelByteRate = inputWAVhdr.fmt.ByteRate/inputWAVhdr.fmt.NumChannels;
	DSPint oneChannelBlockAlign = inputWAVhdr.fmt.BlockAlign/inputWAVhdr.fmt.NumChannels;
	
	outputWAVhdr.data.SubChunk2Size = oneChannelSubChunk2Size*outputWAVhdr.fmt.NumChannels;
	outputWAVhdr.fmt.ByteRate = oneChannelByteRate*outputWAVhdr.fmt.NumChannels;
	outputWAVhdr.fmt.BlockAlign = oneChannelBlockAlign*outputWAVhdr.fmt.NumChannels;


	// Write output WAV header to file
	//-------------------------------------------------
	WriteWavHeader(wav_out,outputWAVhdr);

	//init
	audio_invert_init();

	// Processing loop
	//-------------------------------------------------	
	{
		DSPint sample;
		DSPint BytesPerSample = inputWAVhdr.fmt.BitsPerSample/8;
		const double SAMPLE_SCALE = -(double)(1 << 31);		//2^31
		DSPint iNumSamples = inputWAVhdr.data.SubChunk2Size/(inputWAVhdr.fmt.NumChannels*inputWAVhdr.fmt.BitsPerSample/8);
		

		// exact file length should be handled correctly...
		for(DSPint i=0; i<iNumSamples/BLOCK_SIZE; i++)
		{	
			for(DSPint j=0; j<BLOCK_SIZE; j++)
			{
				for(DSPint k=0; k<inputWAVhdr.fmt.NumChannels; k++)
				{	
					sample = 0; //debug
					fread(&sample, BytesPerSample, 1, wav_in);
					sample = sample << (32 - inputWAVhdr.fmt.BitsPerSample); // force signextend
					tempBuffer[k][j] = FRACT_NUM(sample / SAMPLE_SCALE);				// scale sample to 1.0/-1.0 range	
	
				}
			}
			if(enable==1)
			{
			processing();
			}
			for(DSPint j=0; j<BLOCK_SIZE; j++)
			{
				for(DSPint k=0; k<outputWAVhdr.fmt.NumChannels; k++)
				{	
					sample = sampleBuffer[k][j].toLong();	// crude, non-rounding 			
					sample = sample >> (32 - inputWAVhdr.fmt.BitsPerSample);
					fwrite(&sample, outputWAVhdr.fmt.BitsPerSample/8, 1, wav_out);		
				}
			}		
		}
	}
	
	// Close files
	//-------------------------------------------------	
	fclose(wav_in);
	fclose(wav_out);
	//-------------------------------------------------	

	return 0;
}