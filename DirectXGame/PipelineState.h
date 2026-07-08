#pragma once
#include <d3d12.h>

class PipelineState
{
public:
	// 生成
	void Create(D3D12_GRAPHICS_PIPELINE_STATE_DESC desc);

	// getter
	ID3D12PipelineState* Get();

	// コンストラクタ
	PipelineState();
	// デストラクタ
	~PipelineState();

private:
	ID3D12PipelineState* pipelineState_ = nullptr;
};