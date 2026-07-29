#include "Test.hlsli"

Texture2D<float4> gTexture : register(t0); //SRV     register => t
SamplerState gSampler : register(s0);       //Sampler register => s

struct PixelShaderOutput
{
	float4 color : SV_TARGET0;
};

PixelShaderOutput main(VertexShaderOutput input)
{
	PixelShaderOutput output;
	
	float2 uv = input.texcoord;
	float4 textureColor = gTexture.Sample(gSampler,uv);
	
	//grayscale
    float value = dot(textureColor.rgb, float3(0.2125f, 0.7154f, 0.0721f));
    output.color = float4(value, value, value, textureColor.a);
	
	return output;
}