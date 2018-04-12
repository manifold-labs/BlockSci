
//
//  script_variant.cpp
//  blocksci
//
//  Created by Harry Kalodner on 4/11/18.
//

#include "script_variant.hpp"

#include <blocksci/chain/transaction.hpp>
#include <blocksci/address/equiv_address.hpp>

namespace blocksci {

	Transaction AnyScript::getFirstTransaction() const {
		return mpark::visit([&](auto &scriptAddress) { return scriptAddress.getFirstTransaction(); }, wrapped);
	}

    ranges::optional<Transaction> AnyScript::getTransactionRevealed() const {
    	return mpark::visit([&](auto &scriptAddress) { return scriptAddress.getTransactionRevealed(); }, wrapped);
    }

	EquivAddress AnyScript::getEquivAddresses(bool nestedEquivalent) const {
        return mpark::visit([&](auto &scriptAddress) { return scriptAddress.getEquivAddresses(nestedEquivalent); }, wrapped);
    }

	uint64_t AnyScript::calculateBalance(BlockHeight height) const {
		return mpark::visit([&](auto &scriptAddress) { return scriptAddress.calculateBalance(height); }, wrapped);
	}

    std::vector<OutputPointer> AnyScript::getOutputPointers() const {
    	return mpark::visit([&](auto &scriptAddress) { return scriptAddress.getOutputPointers(); }, wrapped);
    }
    
    std::vector<Output> AnyScript::getOutputs() const {
    	return mpark::visit([&](auto &scriptAddress) { return scriptAddress.getOutputs(); }, wrapped);
    }

    std::vector<Input> AnyScript::getInputs() const {
    	return mpark::visit([&](auto &scriptAddress) { return scriptAddress.getInputs(); }, wrapped);
    }

    std::vector<Transaction> AnyScript::getTransactions() const {
    	return mpark::visit([&](auto &scriptAddress) { return scriptAddress.getTransactions(); }, wrapped);
    }

    std::vector<Transaction> AnyScript::getOutputTransactions() const {
    	return mpark::visit([&](auto &scriptAddress) { return scriptAddress.getOutputTransactions(); }, wrapped);
    }

    std::vector<Transaction> AnyScript::getInputTransactions() const {
    	return mpark::visit([&](auto &scriptAddress) { return scriptAddress.getInputTransactions(); }, wrapped);
    }
}